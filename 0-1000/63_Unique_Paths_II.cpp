// DP
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); if (m <= 0) return 0;
        int n = obstacleGrid[0].size(); if (n <= 0) return 0;
        if (obstacleGrid[0][0]) return 0; 
        
        vector<vector<int>> sumPath(m, vector<int>(n));
        sumPath[0][0] = 1;
        
        for (int i = 1; i < m; i++){
            if (obstacleGrid[i][0]) sumPath[i][0] = 0;
            else sumPath[i][0] = sumPath[i - 1][0];
        }
        
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j]) sumPath[0][j] = 0;
            else sumPath[0][j] = sumPath[0][j - 1];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j]) sumPath[i][j] = 0;
                else sumPath[i][j] = sumPath[i][j - 1] + sumPath[i - 1][j];
            }
        }
        
        return sumPath[m - 1][n - 1];
    }
};
