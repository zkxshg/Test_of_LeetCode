// BFS: O(4 * m * n)
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        
        vector<pair<int, int> > pset;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (isWater[i][j]) 
                    pset.push_back(make_pair(i, j));
        
        vector<vector<int>> H(m, vector<int>(n));
        
        while (!pset.empty()) {
             vector<pair<int, int> > tem;
            
            for (pair<int, int> p : pset) {
                int x = p.first, y = p.second;
                
                if (x > 0 && !isWater[x - 1][y] && !H[x - 1][y]) {
                    H[x - 1][y] = H[x][y] + 1; 
                    tem.push_back(make_pair(x - 1, y));
                }
                if (y > 0 && !isWater[x][y - 1] && !H[x][y - 1]) {
                    H[x][y - 1] = H[x][y] + 1;
                    tem.push_back(make_pair(x, y - 1));
                }
                if (x < m - 1 && !isWater[x + 1][y] && !H[x + 1][y]) {
                    H[x + 1][y] = H[x][y] + 1;
                    tem.push_back(make_pair(x + 1, y));
                }
                if (y < n - 1 && !isWater[x][y + 1] && !H[x][y + 1]) {
                    H[x][y + 1] = H[x][y] + 1;
                     tem.push_back(make_pair(x, y + 1));
                }
            }
            pset = tem;
        }
        
        return H;
    }
};
