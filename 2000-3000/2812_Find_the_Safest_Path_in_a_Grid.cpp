// https://leetcode.com/problems/find-the-safest-path-in-a-grid/?envType=daily-question&envId=2024-05-15
// BFS

class Solution {
public:
    void checkThiefPositions(const vector<vector<int>>& grid, const vector<vector<int>>& safe) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (safe[i][j] != 0) {
                        cout << "Error: Safeness factor of thief position (" << i << ", " << j << ") is not updated correctly." << endl;
                    }
                }
            }
        }
        cout << "All thief positions have correct safeness factor (0)." << endl;
    }

    void checkThiefNeighbours(const vector<vector<int>>& grid, const vector<vector<int>>& safe) {
        int n = grid.size();
        
        // Define directions for neighbour cells
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Iterate over each cell in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // If current cell contains a thief
                if (grid[i][j] == 1) {
                    // Check each neighbour cell
                    for (auto [dx, dy] : directions) {
                        int nx = i + dx, ny = j + dy;
                        // Ensure neighbour cell is within bounds
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[i][j] != 1) {
                            // Check if neighbour cell is updated correctly to 1
                            if (safe[nx][ny] != 1) {
                                cout << "Error: Incorrect safeness factor for neighbour cell (" << nx << ", " << ny << ") of thief position (" << i << ", " << j << ")." << endl;
                            }
                        }
                    }
                }
            }
        }
        cout << "All thief neighbours have correct safeness factor (1)." << endl;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Initialize safeness factor matrix
        vector<vector<int>> safe(n, vector<int>(n, -1));
        vector<pair<int, int>> curSet, nextSet;
        
        // Initialize bfs with thief positions
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    safe[i][j] = 0;
                    curSet.push_back({i, j});
                }
            }
        }
        
        // First BFS to compute safeness factor
        while (!curSet.empty()) {
            nextSet.clear();
            
            for (auto [x, y] : curSet) {
                vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (safe[nx][ny] == -1) {
                            safe[nx][ny] = safe[x][y] + 1;
                            nextSet.push_back({nx, ny});
                        }
                    }
                        
                }
            }
            
            curSet = nextSet;
        }
        // checkThiefPositions(grid, safe);
        // checkThiefNeighbours(grid, safe);
        
        // Second BFS to find maximum safeness factor to reach (n-1, n-1)
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> bfs;
        bfs.push({0, 0});
        dist[0][0] = safe[0][0];

        while (!bfs.empty()) {
            auto [x, y] = bfs.front();
            bfs.pop();
            
            // if (x == n - 1 && y == n - 1) break; // Reached destination
            
            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int min_dist = min(safe[nx][ny], dist[x][y]);
                    
                    if (dist[nx][ny] == -1 || min_dist > dist[nx][ny]) {
                        dist[nx][ny] = min_dist;
                        bfs.push({nx, ny});
                    }
                }
            }
        }
        
        return dist[n - 1][n - 1];
    }
};
