// https://leetcode.com/problems/largest-magic-square/
// DP
class Solution {
public:
    bool ifMagic(vector<vector<int>>& G, int x, int y, int len, vector<vector<int>>& R, vector<vector<int>>& C) {
        int m = G.size(), n = G[0].size();
        
        // if (x + len >= m || y + len >= n) return false;
        //cout << x  << ":" << y << "= " << len << endl;
        
        int sum = R[x][y + len - 1] - R[x][y] + G[x][y]; cout << sum << ":1,";
        
        for (int i = 1; i < len; i++) {
            int tsum = R[x + i][y + len - 1] - R[x + i][y] + G[x + i][y];
            if (sum != tsum) return false;
        }
        
        for (int i = 0; i < len; i++) {
            int tsum = C[x + len - 1][y + i] - C[x][y + i] + G[x][y + i];
            if (sum != tsum) return false;
        }
        
        int ld = 0; for (int i = 0; i < len; i++) ld += G[x + i][y + i]; cout << ld << ":2,";
        if (ld != sum) return false;
        
        int rd = 0; for (int i = 0; i < len; i++) rd += G[x + i][y + len - 1 - i]; cout << rd << endl;
        if (rd != sum) return false;
        
        return true;
    }
    
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        if (m == 1 || n == 1) return 1;
        
        vector<vector<int>> rsum(m, vector<int>(n));
        for (int i = 0; i < m; i++) rsum[i][0] = grid[i][0];
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++) 
                rsum[i][j] = rsum[i][j - 1] + grid[i][j];
        
        
        vector<vector<int>> csum(m, vector<int>(n));
        for (int i = 0; i < n; i++) csum[0][i] = grid[0][i];
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++) 
                csum[j][i] = csum[j - 1][i] + grid[j][i];
            
        vector<pair<int, int> > cand;
        for (int i = 0; i < m - 1; i++) 
            for (int j = 0; j < n - 1; j++) 
                    cand.push_back(make_pair(i, j));
        
        int res = 1;
        for (auto& p : cand) {
            
            int x = p.first, y = p.second;
            
            int l = res;
            while (x + l < m && y + l < n) {
                if (rsum[x][y + l] - rsum[x][y] == csum[x + l][y] - csum[x][y])  {
                    
                    if (ifMagic(grid, x, y, l + 1, rsum, csum)) res = max(res, l + 1);
                }
                l++;
            }
        }
        
        return res;
    }
};
