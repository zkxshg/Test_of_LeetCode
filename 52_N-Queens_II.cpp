// https://leetcode.com/problems/n-queens-ii/
// backtracking
class Solution {
public:
    int sol, N;
    
    void nextR(int row, vector<vector<int> > board) {
        vector<int>& R = board[row];
        
        for (int i = 0; i < N; i++) {
            if (!R[i]) {
                if (row == N - 1) sol++;
                else {
                    vector<vector <int>> nB = board;
                    for (int j = row + 1; j < N; j++) {
                        nB[j][i] = 1;
                        if (j - row < N - i) nB[j][i + j - row] = 1;
                        if (j - row <= i) nB[j][i - j + row] = 1;
                    }
                    nextR(row + 1, nB);
                }
            }
        }
    }
    
    int totalNQueens(int n) {
        if (n == 1) return 1;
        else if (n < 4) return 0;
        
        sol = 0; N = n;
        vector<vector<int> > board(N, vector<int>(N));
        nextR(0, board);
        
        return sol;
    }
};
