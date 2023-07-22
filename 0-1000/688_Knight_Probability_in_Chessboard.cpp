// https://leetcode.com/problems/knight-probability-in-chessboard/description/
// DP

class Solution {
public:
    #define col column
    int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    bool isValid(int x, int y, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, 
            vector<vector<double>>(n, vector<double>(n, 0.0)));

        dp[0][row][col] = 1.0;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < n; l++) {
                    if (dp[i][j][l] > 0) {
                        for (int m = 0; m < 8; m++) {
                            int newRow = j + dir[m][0], newCol = l + dir[m][1];

                            if (isValid(newRow, newCol, n)) {
                                dp[i + 1][newRow][newCol] += dp[i][j][l] / 8;
                            }
                        }
                    }
                }
            }
        }

        double probability = 0.0;
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                probability += dp[k][j][l];
            }
        }

        return probability;
        
    }
};
