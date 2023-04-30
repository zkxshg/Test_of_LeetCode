// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int len = grid.size();
        if (len == 0) return 0;
        
        int wid = grid[0].size();     
        if (wid == 0) return 0;
        
        vector<vector<int>> marki(len, vector<int>(wid, 0));
        int result = 0;
        
        for (int i = 0; i < len; i++){
            for (int j = 0; j < wid; j++){
                if (grid[i][j] == '1' && marki[i][j] == 0){
                    result++;
                    marki[i][j] = result;
                    DFS(grid, marki, i, j);
                }
            }
       
        }
        return result;
    }
    
    void DFS(vector<vector<char>>& grid, vector<vector<int>>& marki, int x, int y){
        int len = grid.size();
        int wid = grid[0].size();
        
        for (int i = x - 1; i >= 0; i--){
            if (grid[i][y] == '0') break;
            else if (marki[i][y] > 0) break;
            else {
                marki[i][y] = marki[x][y];
                DFS(grid, marki, i, y);
            }
        }
        
        for (int i = x + 1; i < len; i++){
            if (grid[i][y] == '0') break;
            else if (marki[i][y] > 0) break;
            else {
                marki[i][y] = marki[x][y];
                DFS(grid, marki, i, y);
            }
        }
        
        for (int j = y + 1; j < wid; j++){
            if (grid[x][j] == '0') break;
            else if (marki[x][j] > 0) break;
            else {
                marki[x][j] = marki[x][y];
                DFS(grid, marki, x, j);
            }
        }
        
        for (int j = y - 1; j >= 0; j--){
            if (grid[x][j] == '0') break;
            else if (marki[x][j] > 0) break;
            else {
                marki[x][j] = marki[x][y];
                DFS(grid, marki, x, j);
            }
        }
    }
};
