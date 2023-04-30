// https://leetcode.com/problems/shortest-bridge/
// BFS

class Solution {
public:
    int m, n;
    
    vector<vector<int>> deepCopy(vector<vector<int>>& grid) {      
        vector<vector<int> > dc(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dc[i][j] = grid[i][j];
        
        return dc;
    }
    
    void expand(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 2;
        
        if (i > 0 && grid[i - 1][j] == 1) expand(grid, i - 1, j);

        if (j > 0 && grid[i][j - 1] == 1) expand(grid, i, j - 1);
        
        if (i < m - 1 && grid[i + 1][j] == 1) expand(grid, i + 1, j);

        if (j < n - 1 && grid[i][j + 1] == 1) expand(grid, i, j + 1);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size(); n = m;
        
        int x = -1, y = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    x = i; y = j; break;
                }
            }
            if (x >= 0 || y >= 0) break;
        }
        
        expand(grid, x, y);

        int dist = 0; bool cnt = false;
        while (!cnt) {
            dist++;
            
            vector<vector<int> > nex = deepCopy(grid);
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] != 1) continue;
                    
                    if (i > 0 && grid[i - 1][j] != 1) {
                        if (grid[i - 1][j] == 2) {
                            cnt = true; break;
                        }
                        nex[i - 1][j] = 1;
                    }

                    if (j > 0 && grid[i][j - 1] != 1) {
                        if (grid[i][j - 1] == 2) {
                            cnt = true; break;
                        }
                        nex[i][j - 1] = 1;
                    }

                    if (i < m - 1 && grid[i + 1][j] != 1) {
                        if (grid[i + 1][j] == 2) {
                            cnt = true; break;
                        }
                        nex[i + 1][j] = 1;
                    }

                    if (j < n - 1&& grid[i][j + 1] != 1) {
                        if (grid[i][j + 1] == 2) {
                            cnt = true; break;
                        }
                        nex[i][j + 1] = 1;
                    }
                }
                
                if (cnt) break;
            }
            
            grid = nex;
        }
        
        return dist - 1;
    }
}; 
