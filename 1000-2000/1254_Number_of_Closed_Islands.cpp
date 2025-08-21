// https://leetcode.com/problems/number-of-closed-islands/
// BFS

class Solution {
public:
    int m, n;
    
    void expand(vector<vector<int>>& grid, int i, int j, int num) {
        grid[i][j] = num;
        
        if (i > 0 && grid[i - 1][j] < 0) {
            grid[i - 1][j] = num; 
            expand(grid, i - 1, j, num);
        }
        
        if (j > 0 && grid[i][j - 1] < 0) {
            grid[i][j - 1] = num;
            expand(grid, i, j - 1, num);
        }
        
        if (i < m - 1 && grid[i + 1][j] < 0) {
            grid[i + 1][j] = num;
            expand(grid, i + 1, j, num);
        }
        
        if (j < n - 1&& grid[i][j + 1] < 0) {
            grid[i][j + 1] = num;
            expand(grid, i, j + 1, num);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) grid[i][j] = -1;
                else grid[i][j] = 0;
            }
        }
                
        int cnt = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] < 0) {
                    expand(grid, i, j, cnt);
                    cnt++;
                }
            }
        }
        
        unordered_map<int, int> cld;
        for (int i = 1; i < cnt; i++) cld[i]++;
        
        for (int i = 0; i < m; i++) {
            if (grid[i][0]) cld[grid[i][0]] = 0;
            if (grid[i][n - 1]) cld[grid[i][n - 1]] = 0;
        }
        
        for (int j = 0; j < n; j++) {
            if (grid[0][j]) cld[grid[0][j]] = 0;
            if (grid[m - 1][j]) cld[grid[m - 1][j]] = 0;
        }
        
        int res = 0;
        for (int i = 1; i < cnt; i++) 
            if (cld[i]) 
                res++;
        
        return res;  
    }
};
