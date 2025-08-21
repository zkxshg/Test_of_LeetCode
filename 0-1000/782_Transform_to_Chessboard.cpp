// https://leetcode.com/problems/transform-to-chessboard/
// math + bit maniputation + matrix

class Solution {
public:
    int biNum(vector<int>& board) {
        int res = 0;
        for (int i : board) res = res * 2 + i;
        return res;
    }
    
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        
        vector<int>& F = board[0];
        
        // Check (1)
        int one = 0, zero = 0;
        for (int i : F) {
            if (i) one++;
            else zero++;
        }
        
        if (abs(one - zero) > 1) return -1;
        
        int A = biNum(F);
        
        // Check (2)
        int aN = 1, bN = 0;
        unordered_map<int, int> cls; cls[0] = 1;
        
        for (int i = 1; i < n; i++) {
            int B = biNum(board[i]);
            
            if (A == B) {
                aN++; cls[i] = 1;
            }
            else if ((A ^ B) == pow(2, n) - 1) bN++;
            else return -1;
        }
        
        if (abs(aN - bN) > 1) return -1;
        
        // cal steps
        int res = 0;
        
        if (n % 2) {
            int aim = 0; if (one > zero) aim = 1;
            
            for (int i = 0; i < n; i += 2) 
                if (F[i] != aim) res++;
            
            aim = 1; if (aN < bN) aim = 0;
            for (int i = 0; i < n; i += 2)
                if (cls[i] != aim)
                    res++;
        }
        else {
            one = 0; zero = 0;
            for (int i = 0; i < n; i += 2) {
                if (F[i]) zero++;
                else one++;
            }
            res += min(one, zero);

            one = 0; zero = 0;
            for (int i = 1; i < n; i += 2) {
                if (cls[i]) one++;
                else zero++;
            }
            res += min(one, zero);
        }
        
        
        return res;
    }
};
