// https://leetcode.com/problems/count-sub-islands/
// BFS

class Solution {
public:
    bool bfs(vector<vector<int>>& G2, int x,  int y, vector<vector<int>>& S, vector<vector<int>>& G1) {
        int m = G1.size(), n = G1[0].size();
        bool res = true;
        
        if (!G1[x][y]) res = false;
        
        if (x > 0 && G2[x - 1][y] && !S[x - 1][y]) {
            S[x - 1][y] = 1;
            if (!bfs(G2, x - 1, y, S, G1)) res = false;
        }
        
        if (x < m - 1 && G2[x + 1][y] && !S[x + 1][y]) {
            S[x + 1][y] = 1;
            if (!bfs(G2, x + 1, y, S, G1)) res = false;
        }
        
        if (y > 0 && G2[x][y - 1] && !S[x][y - 1]) {
            S[x][y - 1] = 1;
            if (!bfs(G2, x, y - 1, S, G1)) res = false;
        }
        
        if (y < n - 1 && G2[x][y + 1] && !S[x][y + 1]) {
            S[x][y + 1] = 1;
            if (!bfs(G2, x, y + 1, S, G1)) res = false;
        }
        
        return res;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        
        vector<vector<int> > scan(m, vector<int>(n));
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (scan[i][j] || !grid2[i][j]) continue;
                if (bfs(grid2, i, j, scan, grid1)) res++;
            }
        }
        
        return res;
    }
};
