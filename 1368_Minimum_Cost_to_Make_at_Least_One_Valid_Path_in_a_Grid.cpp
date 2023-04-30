// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
// BFS

class Solution {
public:
    void print2D(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << M[i][j]; if (j < n - 1) cout << ",";
            }
            cout << endl;
        }
    }
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int> > cost(m, vector<int>(n, 10001));
        cost[0][0] = 0;
        
        set<pair<int, int> > bfs; bfs.insert({0, 0});
        
        while (!bfs.empty()) {
            set<pair<int, int> > nex;
            
            for (auto& p : bfs) {
                int x = p.first, y = p.second;
                //cout << x << ":" << y << endl;
                
                if (x < m - 1) {
                    if (grid[x][y] == 3) {
                        if (cost[x][y] < cost[x + 1][y]) {
                            cost[x + 1][y] = cost[x][y]; nex.insert({x + 1, y});
                        }
                    }
                    else if (cost[x][y] + 1< cost[x + 1][y]) {
                        cost[x + 1][y] = cost[x][y] + 1; nex.insert({x + 1, y});
                    }
                }
                
                if (x > 0) {
                    if (grid[x][y] == 4) {
                        if (cost[x][y] < cost[x - 1][y]) {
                            cost[x - 1][y] = cost[x][y]; nex.insert({x - 1, y});
                        }
                    }
                    else if (cost[x][y] + 1 < cost[x - 1][y]) {
                        cost[x - 1][y] = cost[x][y] + 1; nex.insert({x - 1, y});
                    }
                }
                
                if (y < n - 1) {
                    if (grid[x][y] == 1) {
                        if (cost[x][y] < cost[x][y + 1]) {
                            cost[x][y + 1] = cost[x][y]; nex.insert({x, y + 1});
                        }
                    }
                    else if (cost[x][y] + 1 < cost[x][y + 1]) {
                        cost[x][y + 1] = cost[x][y] + 1; nex.insert({x, y + 1});
                    }
                }
                
                if (y > 0) {
                    if (grid[x][y] == 2) {
                        if (cost[x][y] < cost[x][y - 1]) {
                            cost[x][y - 1] = cost[x][y]; nex.insert({x, y - 1});
                        }
                    }
                    else if (cost[x][y] + 1 < cost[x][y - 1]) {
                        cost[x][y - 1] = cost[x][y] + 1; nex.insert({x, y - 1});
                    }
                }
            }
            
            bfs = nex;
        }
        
        //print2D(cost);
        return cost[m - 1][n - 1];
    }
};
