// https://leetcode.com/problems/swim-in-rising-water/
// BFS

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> mark(n, vector<int>(n)); mark[0][0] = 1;
        
        vector<pair<int, int> > bfs;
        bfs.push_back(make_pair(0, 0));
        
        int t = grid[0][0];
        while (!mark[n - 1][n - 1]) {
            vector<pair<int, int> > nb;
            
            for (auto& p : bfs) BF(grid, mark, nb, p.first, p.second, t);
            
            bfs = nb; t++;
        }
        
        return t - 1;
    }
    
    void BF(vector<vector<int>>& grid, vector<vector<int>>& M, vector<pair<int, int> >& B, int x, int y, int t) {
        bool contour = false; int n = grid.size();
        
        if (x > 0 && !M[x - 1][y]) {
             if (grid[x - 1][y] <= t) {
                 M[x - 1][y] = 1;
                 BF(grid, M, B, x - 1, y, t);
             }
            else contour = true;
        }
        
        if (y > 0 && !M[x][y - 1]) {
             if (grid[x][y - 1] <= t) {
                 M[x][y - 1] = 1;
                 BF(grid, M, B, x, y - 1, t);
             }
            else contour = true;
        }
        
        if (x < n - 1 && !M[x + 1][y]) {
             if (grid[x + 1][y] <= t) {
                 M[x + 1][y] = 1;
                 BF(grid, M, B, x + 1, y, t);
             }
            else contour = true;
        }
        
        if (y < n - 1 && !M[x][y + 1]) {
             if (grid[x][y + 1] <= t) {
                 M[x][y + 1] = 1;
                 BF(grid, M, B, x, y + 1, t);
             }
            else contour = true;
        }
        
        if (contour) B.push_back(make_pair(x, y)); 
    }
};
