// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// BFS

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(); 
        
        if (m == 1 && n == 1) return 0;
        
        vector<vector<pair<int, int> > > vp(k + 1);
        
        vector<vector<int>> step(m, vector<int>(n, k + 1));
        
        vp[0].push_back(make_pair(0, 0));
        
        int count = 0;
        bool emp = false;
        while (!emp) {
            emp = true; count++;
            
            vector<vector<pair<int, int> > > tmp(k + 1);
            
            for (int i = 0; i <= k; i++) {
                
                for (auto& p : vp[i]) {
                    int x = p.first, y = p.second;
                    
                    if (x > 0) {
                        if (!grid[x - 1][y] && step[x - 1][y] > i) {
                           tmp[i].push_back(make_pair(x - 1, y)); step[x - 1][y] = i;
                        }
                        else if (i < k && step[x - 1][y] > i + 1) {
                            tmp[i + 1].push_back(make_pair(x - 1, y)); step[x - 1][y] = i + 1;
                        }  
                    } 
                    
                    if (y > 0) {
                        if (!grid[x][y - 1] && step[x][y - 1] > i) {
                           tmp[i].push_back(make_pair(x, y - 1)); step[x][y - 1] = i;
                        }
                        else if (i < k && step[x][y - 1] > i + 1) {
                            tmp[i + 1].push_back(make_pair(x, y - 1)); step[x][y - 1] = i + 1;
                        }
                    } 
                    
                    if (x < m - 1) {
                        if (!grid[x + 1][y] && step[x + 1][y] > i) {
                            tmp[i].push_back(make_pair(x + 1, y)); step[x + 1][y] = i;
                        }
                        else if (i < k && step[x + 1][y] > i + 1) {
                            tmp[i + 1].push_back(make_pair(x + 1, y)); step[x + 1][y] = i + 1;
                        }
                    } 
                    
                    if (y < n - 1) {
                        if (!grid[x][y + 1] && step[x][y + 1] > i) {
                            tmp[i].push_back(make_pair(x, y + 1)); step[x][y + 1] = i;
                        }
                        else if (i < k && step[x][y + 1] > i + 1) {
                            tmp[i + 1].push_back(make_pair(x, y + 1)); step[x][y + 1] = i + 1;
                        }
                    } 
                }

                if (!tmp[i].empty()) emp = false;
            }
            
            if (step[m - 1][n - 1] <= k) return count;
            
            // for (int i = 0; i < m; i++) {
            //     for (int j = 0; j < n; j++) cout << grid[i][j] << ","; cout << endl;
            // }
            // cout << endl;
            
            vp = tmp;
        }
        
        return -1;
    }
};
