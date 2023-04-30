//https://leetcode.com/problems/shortest-path-in-binary-matrix/

// DFS
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        
        int m = grid.size(), n = grid[0].size();
        
        int MAX = 1e5;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) grid[i][j] = MAX;
        
        grid[0][0] = 1;
        
        /* for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cout << grid[i][j] << ", ";
            cout << endl;
        } */
            
        vector<pair<int, int> > set = {make_pair(0, 0)};
        
        while (!set.empty()) {
            vector<pair<int, int> > temS;

            for (pair<int, int> p : set) {
                int i = p.first, j = p.second;
                
                if (grid[i][j] < MAX) {
                    if (i > 0 && !grid[i - 1][j]) {
                        grid[i - 1][j] = grid[i][j] + 1;
                        temS.push_back(make_pair(i - 1, j));
                    }
                        
                    if (i > 0 && j > 0 && !grid[i - 1][j - 1]) {
                        grid[i - 1][j - 1] = grid[i][j] + 1;
                        temS.push_back(make_pair(i - 1, j - 1));
                    }
                    
                    if (i > 0 && j < n - 1 && !grid[i - 1][j + 1]) {
                        grid[i - 1][j + 1] = grid[i][j] + 1;
                        temS.push_back(make_pair(i - 1, j + 1));
                    }
                    
                    if (j < n - 1 && !grid[i][j + 1]) {
                        grid[i][j + 1] = grid[i][j] + 1;
                        temS.push_back(make_pair(i, j + 1));
                    }
                    
                    if (j > 0 && !grid[i][j - 1]) {
                        grid[i][j - 1] = grid[i][j] + 1;
                        temS.push_back(make_pair(i, j - 1));
                    }
                    
                    if (i < m - 1 && !grid[i + 1][j]) {
                        grid[i + 1][j] = grid[i][j] + 1;
                        temS.push_back(make_pair(i + 1, j ));
                    }
                    
                    if (i < m - 1 && j > 0 && !grid[i + 1][j - 1]) {
                        grid[i + 1][j - 1] = grid[i][j] + 1;
                        temS.push_back(make_pair(i + 1, j - 1));
                    }
                    
                    if (i < m - 1 && j < n - 1 && !grid[i + 1][j + 1]) {
                        grid[i + 1][j + 1] = grid[i][j] + 1;
                        temS.push_back(make_pair(i + 1, j + 1));
                    } 
                }
            }
            set = temS;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cout << grid[i][j] << ", ";
            cout << endl;
        }
        
        if (grid[m - 1][n - 1] < MAX && grid[m - 1][n - 1] > 0) return grid[m - 1][n - 1];
        return -1;
    }
};

// BFS
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        
        int m = grid.size(), n = grid[0].size();
        
        int MAX = 1e5;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) grid[i][j] = MAX;
        
        grid[0][0] = 1;
        
        /* for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cout << grid[i][j] << ", ";
            cout << endl;
        } */
            
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] < MAX) {
                    if (i > 0 && grid[i - 1][j] < MAX) {
                        if (!grid[i - 1][j]) grid[i - 1][j] = grid[i][j] + 1;
                        else grid[i - 1][j] = min(grid[i - 1][j], grid[i][j] + 1);
                    }
                        
                    
                    if (i > 0 && j > 0 && grid[i - 1][j - 1] < MAX) {
                        if (!grid[i - 1][j - 1]) grid[i - 1][j - 1] = grid[i][j] + 1;
                        else grid[i - 1][j - 1] = min(grid[i - 1][j - 1], grid[i][j] + 1);
                    }
                    
                    if (i > 0 && j < n - 1 && grid[i - 1][j + 1] < MAX) {
                        if (!grid[i - 1][j + 1]) grid[i - 1][j + 1] = grid[i][j] + 1;
                        else grid[i - 1][j + 1] = min(grid[i - 1][j + 1], grid[i][j] + 1);
                    }
                    
                    if (j < n - 1 && grid[i][j + 1] < MAX) {
                        if (!grid[i][j + 1]) grid[i][j + 1] = grid[i][j] + 1;
                        else grid[i][j + 1] = min(grid[i][j + 1], grid[i][j] + 1);
                    }
                    
                    if (j > 0 && grid[i][j - 1] < MAX) {
                        if (!grid[i][j - 1]) grid[i][j - 1] = grid[i][j] + 1;
                        else grid[i][j - 1] = min(grid[i][j - 1], grid[i][j] + 1);
                    }
                    
                    if (i < m - 1 && grid[i + 1][j] < MAX) {
                        if (!grid[i + 1][j]) grid[i + 1][j] = grid[i][j] + 1;
                        else grid[i + 1][j] = min(grid[i + 1][j], grid[i][j] + 1);
                    }
                    
                    if (i < m - 1 && j > 0 && grid[i + 1][j - 1] < MAX) {
                        if (!grid[i + 1][j - 1]) grid[i + 1][j - 1] = grid[i][j] + 1;
                        else grid[i + 1][j - 1] = min(grid[i + 1][j - 1], grid[i][j] + 1);
                    }
                    
                    if (i < m - 1 && j < n - 1 && grid[i + 1][j + 1] < MAX) {
                        if (!grid[i + 1][j + 1]) grid[i + 1][j + 1] = grid[i][j] + 1;
                        else grid[i + 1][j + 1] = min(grid[i + 1][j + 1], grid[i][j] + 1);
                    } 
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cout << grid[i][j] << ", ";
            cout << endl;
        } 
        if (grid[m - 1][n - 1] < MAX) return grid[m - 1][n - 1];
        return -1;
    }
};
