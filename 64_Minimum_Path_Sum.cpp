// DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int len = grid[0].size();
        int wid = grid.size();
        if (len == 0 || wid == 0) return 0;
        
        vector<vector<int>> gridPath(wid+1, vector<int>(len+1, -1));
        return calPath(grid, gridPath, wid, len); 
    }
    int calPath(vector<vector<int>>& grid, vector<vector<int>>& gridPath, int x, int y){
        if (x == 0 || y == 0) return INT_MAX;
        if (x == 1 && y == 1) return grid[0][0];
        
        if (gridPath[x-1][y] < 0) gridPath[x-1][y] = calPath(grid, gridPath, x-1, y);
        if (gridPath[x][y-1] < 0) gridPath[x][y-1] = calPath(grid, gridPath, x, y-1);
        
        if (gridPath[x-1][y] > gridPath[x][y-1]) 
            gridPath[x][y] = gridPath[x][y-1] + grid[x-1][y-1];
        else gridPath[x][y] = gridPath[x-1][y] + grid[x-1][y-1];
        
        return gridPath[x][y];
    }
};
