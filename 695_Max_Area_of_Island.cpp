// https://leetcode.com/problems/max-area-of-island/
// BFS
class Solution {
public:
    unordered_map<int, int> regionSize;
    int m, n;
    
    void expand(vector<vector<int>>& grid, int i, int j, int num) {
        if (i > 0 && grid[i - 1][j] < 0) {
            grid[i - 1][j] = num; regionSize[num]++;
            expand(grid, i - 1, j, num);
        }
        
        if (j > 0 && grid[i][j - 1] < 0) {
            grid[i][j - 1] = num; regionSize[num]++;
            expand(grid, i, j - 1, num);
        }
        
        if (i < m - 1 && grid[i + 1][j] < 0) {
            grid[i + 1][j] = num; regionSize[num]++;
            expand(grid, i + 1, j, num);
        }
        
        if (j < n - 1&& grid[i][j + 1] < 0) {
            grid[i][j + 1] = num; regionSize[num]++;
            expand(grid, i, j + 1, num);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j]) 
                    grid[i][j] = -1;
        
        regionSize.clear();
        
        int num = 1, res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] < 0) {
                    grid[i][j] = num; regionSize[num]++;
                    
                    expand(grid, i, j, num);
                    
                    res = max(res, regionSize[num]);
                    
                    num++;
                }
            }
        }
        
        return res;
        
    }
};
