// DP + hash map
class Solution {
public:
    bool winnerSquareGame(int n) { 
        unordered_map<int, bool> numWin;
        
        for (int i = 0; i <= n; i++) numWin[i] = false;
        numWin[1] = true;
        
        for (int i = 2; i <= n; i++) {
            int sq = sqrt(i);
            for (int j = 1; j <= sq; j++) {
                if (!numWin[i - j * j]) {
                    numWin[i] = true;
                    break;
                }
            }
        }
        
        return numWin[n];
    }
};
