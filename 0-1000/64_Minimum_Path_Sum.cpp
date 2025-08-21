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

// DP2
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int len = grid.size();
        if (len == 0) return 0;
        int wid = grid[0].size();     
        if (wid == 0) return 0;
        
        vector<vector<int>> minSum(len, vector<int>(wid, -1));
        
        int result = minPath(grid, minSum, len - 1, wid - 1);
        return result;
    }
    
    int minPath(vector<vector<int>>& grid, vector<vector<int>>& minSum, int x, int y) {
        if (x == 0 && y == 0) return grid[0][0];
        else if (x == 0) {
            if (minSum[0][y - 1] < 0) minSum[0][y - 1] = minPath(grid, minSum, 0, y - 1);
            return minSum[0][y - 1] + grid[x][y];
        }
        else if (y == 0) {
            if (minSum[x - 1][0] < 0) minSum[x - 1][0] = minPath(grid, minSum, x - 1, 0);
            return minSum[x - 1][0] + grid[x][y];
        }
        
        if (minSum[x][y - 1] < 0) minSum[x][y - 1] = minPath(grid, minSum, x, y - 1);
        int leftMin = minSum[x][y - 1];
        
        if (minSum[x - 1][y] < 0) minSum[x - 1][y] = minPath(grid, minSum, x - 1, y);
        int upMin = minSum[x - 1][y];
        
        if (leftMin < upMin) minSum[x][y] = leftMin + grid[x][y];
        else minSum[x][y] = upMin + grid[x][y];
        
        return minSum[x][y];
    }
};
