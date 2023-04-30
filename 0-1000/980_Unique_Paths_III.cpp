// DFS + backtracking
class Solution {
public:
    int pathNum;
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();    if (m <= 0) return 0;
        int n = grid[0].size(); if (n <= 0) return 0;  
        pathNum = 0;
        
        int zeroNum = 0, sx = -1, sy = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }

                if (grid[i][j] == 0) zeroNum++;
            }
        }
        
        if (sx < 0 || sy < 0) return 0;
        
        vector<vector<int>> temG(grid);

        if (sx > 0) search(temG, zeroNum, sx - 1, sy);
        if (sy > 0) search(temG,zeroNum, sx, sy - 1);
        if (sx < m - 1) search(temG, zeroNum, sx + 1, sy);
        if (sy < n - 1) search(temG, zeroNum, sx, sy + 1);
        
        return pathNum;
    }
    
    void search(vector<vector<int>> grid, int zeroNum, int x, int y) {
        if (grid[x][y] == 0) {
            int m = grid.size(),  n = grid[0].size(); 

            grid[x][y] = -1;
            zeroNum--;
            
            if (zeroNum == 0) {
                if (x > 0 && grid[x - 1][y] == 2) pathNum++;
                else if (y > 0 && grid[x][y - 1] == 2) pathNum++;
                else if (x < m - 1 && grid[x + 1][y] == 2) pathNum++;
                else if (y < n - 1 && grid[x][y + 1] == 2) pathNum++;
            } else {
                if (x > 0 && grid[x - 1][y] == 0) search(grid, zeroNum, x - 1, y);
                if (y > 0 && grid[x][y - 1] == 0) search(grid, zeroNum, x, y - 1);
                if (x < m - 1 && grid[x + 1][y] == 0) search(grid, zeroNum, x + 1, y);
                if (y < n - 1 && grid[x][y + 1] == 0) search(grid, zeroNum, x, y + 1);
            }
            
        } else if (grid[x][y] == 2 && zeroNum == 0) pathNum++;
    }
};
