// https://leetcode.com/problems/cherry-pickup-ii/
// DP
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        
        vector<vector<vector<int> > > che(row, vector<vector<int> >(col, vector<int>(col, -1000)));
        
        che[0][0][col - 1] = grid[0][0] + grid[0][col - 1];
        
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < col; k++) {
                    vector<vector<int> >& rowM = che[i - 1];
                    int maxA = rowM[j][k];
                    
                    if (j > 0) {
                        maxA = max(maxA, rowM[j - 1][k]);
                        if (k > 0) maxA = max(maxA, rowM[j - 1][k - 1]);
                        if (k < col - 1) maxA = max(maxA, rowM[j - 1][k + 1]);
                    }
                    
                    
                    if (j < col - 1) {
                        maxA = max(maxA, rowM[j + 1][k]);
                        if (k > 0) maxA = max(maxA, rowM[j + 1][k - 1]);
                        if (k < col - 1) maxA = max(maxA, rowM[j + 1][k + 1]);
                    }
                    
                    if (k > 0) maxA = max(maxA, rowM[j][k - 1]);
                    if (k < col - 1) maxA = max(maxA, rowM[j][k + 1]);
                    
                    if (j == k) che[i][j][k] = maxA + grid[i][j];
                    else che[i][j][k] = maxA + grid[i][j] + grid[i][k];
                }
            } 
        }
        
        int res = 0;
        vector<vector<int> >& lastR = che[row - 1];
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < col; j++) res = max(res, lastR[i][j]);
        }
        return res;
    }
};
