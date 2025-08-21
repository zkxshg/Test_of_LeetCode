// https://leetcode.com/problems/pacific-atlantic-water-flow/
// bfs

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        // Pacfific Ocean
        vector<vector<int> > pac(m, vector<int>(n));
        vector<pair<int, int> > bfs;
        for (int i = 0; i < m; i++) {
            pac[i][0]++; bfs.push_back(make_pair(i, 0));
        }
        for (int j = 0; j < n; j++) {
            pac[0][j]++; bfs.push_back(make_pair(0, j));
        }
        
        while (!bfs.empty()) {
            vector<pair<int, int> > tem;
            for (auto& p : bfs) {
                int x = p.first, y = p.second;
                
                if (x > 0 && !pac[x - 1][y] && heights[x - 1][y] >= heights[x][y]) {
                    pac[x - 1][y] = 1; tem.push_back(make_pair(x - 1, y));
                }
                
                if (y > 0 && !pac[x][y - 1] && heights[x][y - 1] >= heights[x][y]) {
                    pac[x][y - 1] = 1; tem.push_back(make_pair(x, y - 1));
                }
                
                if (x < m - 1 && !pac[x + 1][y] && heights[x + 1][y] >= heights[x][y]) {
                    pac[x + 1][y] = 1; tem.push_back(make_pair(x + 1, y));
                }
                
                if (y < n - 1 && !pac[x][y + 1] && heights[x][y + 1] >= heights[x][y]) {
                    pac[x][y + 1] = 1; tem.push_back(make_pair(x, y + 1));
                }
            }
            
            bfs = tem;
        }
        
        // Atlantic Ocean
        vector<vector<int> > atl(m, vector<int>(n));
        bfs.clear();
        for (int i = 0; i < m; i++) {
            atl[i][n - 1]++; bfs.push_back(make_pair(i, n - 1));
        }
        for (int j = 0; j < n; j++) {
            atl[m - 1][j]++; bfs.push_back(make_pair(m - 1, j));
        }
        
        while (!bfs.empty()) {
            vector<pair<int, int> > tem;
            for (auto& p : bfs) {
                int x = p.first, y = p.second;
                
                if (x > 0 && !atl[x - 1][y] && heights[x - 1][y] >= heights[x][y]) {
                    atl[x - 1][y] = 1; tem.push_back(make_pair(x - 1, y));
                }
                
                if (y > 0 && !atl[x][y - 1] && heights[x][y - 1] >= heights[x][y]) {
                    atl[x][y - 1] = 1; tem.push_back(make_pair(x, y - 1));
                }
                
                if (x < m - 1 && !atl[x + 1][y] && heights[x + 1][y] >= heights[x][y]) {
                    atl[x + 1][y] = 1; tem.push_back(make_pair(x + 1, y));
                }
                
                if (y < n - 1 && !atl[x][y + 1] && heights[x][y + 1] >= heights[x][y]) {
                    atl[x][y + 1] = 1; tem.push_back(make_pair(x, y + 1));
                }
            }
            
            bfs = tem;
        }
        
        
        vector<vector<int> > res;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j]) 
                    res.push_back({i, j});
        
        return res;
        
    }
};
