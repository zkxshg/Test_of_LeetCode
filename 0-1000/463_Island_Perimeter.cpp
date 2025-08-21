// brute-force
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int len = grid.size();
        if (len <= 0) return 0;
        int wid = grid[0].size();
        if (wid <= 0) return 0;
        
        int result = 0;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j]) result += calPeri(grid, i, j);
            }
        }
        
        return result;
    }
    
    int calPeri(vector<vector<int>>& grid, int i, int j) {
        int len = grid.size();
        int wid = grid[0].size();
        
        int peri = 0;
        
        if (i == 0) peri++;
        else if (!grid[i-1][j]) peri++;
        
        if (i == len - 1) peri++;
        else if (!grid[i+1][j]) peri++;
        
        if (j == 0) peri++;
        else if (!grid[i][j-1]) peri++;
        
        if (j == wid - 1) peri++;
        else if (!grid[i][j+1]) peri++;
        
        return peri;
    }
};
