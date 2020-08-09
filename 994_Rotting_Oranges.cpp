// BFS
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int len = grid.size(), wid = grid[0].size();

        int count_1 = 0, step = 0, delta_1 = 1;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j] == 1) count_1++;
            }
        }
        
        while (count_1 > 0 && delta_1 > 0) {
            delta_1 = 0;
            
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < wid; j++) {
                    if (grid[i][j] == 1 && ifRott(grid, i, j)) {
                        grid[i][j] = 3;
                        count_1--;
                        delta_1++;
                    }
                }
            }
            
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < wid; j++) {
                    if (grid[i][j] == 3)  grid[i][j] = 2;
                }
            }
            
            step++;
        }
        
        if (count_1 > 0) return -1;
        return step;  
    }
    
    bool ifRott(vector<vector<int>>& grid, int i, int j) {
        int len = grid.size(), wid = grid[0].size();
        
        if (i > 0 && grid[i - 1][j] == 2) return true;
        if (i < len - 1 && grid[i + 1][j] == 2) return true;
        if (j > 0 && grid[i][j - 1] == 2) return true;
        if (j < wid - 1 && grid[i][j + 1] == 2) return true;
        
        return false;
    }
};
