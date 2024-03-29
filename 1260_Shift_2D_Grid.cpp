// https://leetcode.com/problems/shift-2d-grid/
// math

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int> > res(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int j1 = (j + k) % n;
                int i1 = (i + (j + k) / n) % m;
                
                res[i1][j1] = grid[i][j];
            }
        }
        
        return res;
    }
};
