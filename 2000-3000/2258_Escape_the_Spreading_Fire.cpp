// https://leetcode.com/problems/escape-the-spreading-fire/
// BFS

class Solution {
public:
    void print2D(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cout << grid[i][j] << ',';
            cout << endl;
        }
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // === BFS the fire reach time ===
        vector<vector<int> > fire(m, vector<int>(n));
        
        // set the wall and fire
        vector<pair<int, int> > bfs;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) fire[i][j] = -1;
                else if (grid[i][j] == 1) {fire[i][j] = 1; bfs.push_back({i, j});}
            }
        }
        
        // bfs
        int cou = 1;
        while(!bfs.empty()) {
            vector<pair<int, int> > tem; cou++;
            
            for (auto& p : bfs) {
                int x = p.first, y = p.second; 
 
                if (x > 0 && !fire[x - 1][y]) {fire[x - 1][y] = cou;  tem.push_back({x - 1, y});}
                if (y > 0 && !fire[x][y - 1]) {fire[x][y - 1] = cou;  tem.push_back({x, y - 1});}
                if (x < m - 1 && !fire[x + 1][y]) {fire[x + 1][y] = cou;  tem.push_back({x + 1, y});}
                if (y < n - 1 && !fire[x][y + 1]) {fire[x][y + 1] = cou;  tem.push_back({x, y + 1});}
            }
            
            bfs = tem;
        }
        
        
        // === BFS the step time ===
        vector<vector<int> > steps(m, vector<int>(n)); steps[0][0] = 1;
        
        // set the wall
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 2) steps[i][j] = -1;
        
        bfs.clear(); bfs.push_back({0, 0}); cou = 1;
        
        // bfs
        while(!bfs.empty()) {
            vector<pair<int, int> > tem; cou++;
            
            for (auto& p : bfs) {
                int x = p.first, y = p.second; 
 
                if (x > 0 && !steps[x - 1][y] && (!fire[x - 1][y] || fire[x - 1][y] > cou)) {
                    steps[x - 1][y] = cou;  tem.push_back({x - 1, y});
                }
                
                if (y > 0 && !steps[x][y - 1] && (!fire[x][y - 1] || fire[x][y - 1] > cou)) {
                    steps[x][y - 1] = cou;  tem.push_back({x, y - 1});
                }
                
                if (x < m - 1 && !steps[x + 1][y] && (!fire[x + 1][y] || fire[x + 1][y] > cou)) {
                    steps[x + 1][y] = cou;  tem.push_back({x + 1, y});
                }
                else if (x + 1 == m - 1 && y == n - 1 && fire[x + 1][y] == cou) steps[x + 1][y] = cou;
                
                if (y < n - 1 && !steps[x][y + 1] && (!fire[x][y + 1] || fire[x][y + 1] > cou)) {
                    steps[x][y + 1] = cou;  tem.push_back({x, y + 1});
                }
                else if (x == m - 1 && y + 1 == n - 1 && fire[x][y + 1] == cou) steps[x][y + 1] = cou;
            }
            
            bfs = tem;
        }
        
        
        // === Calculate the time delay ===
        vector<vector<int> > delay(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!steps[i][j]) continue;
                
                if (steps[i][j] == -1) delay[i][j] = -1;
                else if (!fire[i][j]) delay[i][j] = 1000000000;
                else delay[i][j] = fire[i][j] - steps[i][j];
                
                if (i == m - 1 && j == n - 1 && fire[i][j] >= steps[i][j]) delay[i][j]++;
            }
        }
        // print2D(fire); cout << endl; print2D(steps); cout << endl; print2D(delay); cout << endl;
        
        if (!delay[m - 1][n - 1]) return -1;
        
        // BFS the final res
        vector<vector<int> > res(m, vector<int>(n, -1));
        
        // set the valid pos
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (delay[i][j] > 0) res[i][j] = 0;
        
        res[0][0] = delay[0][0];
        
        bfs.clear(); bfs.push_back({0, 0}); 
        
        // bfs
        while(!bfs.empty()) {
            vector<pair<int, int> > tem; 
            
            for (auto& p : bfs) {
                int x = p.first, y = p.second; 
 
                if (x > 0 && res[x - 1][y] >= 0 && (!res[x - 1][y] || 
                              (res[x][y] > res[x - 1][y] && res[x][y] <= delay[x - 1][y])) ) {
                    res[x - 1][y] = min(res[x][y], delay[x - 1][y]);  tem.push_back({x - 1, y});
                }
                if (y > 0 && res[x][y - 1] >= 0 && (!res[x][y - 1] ||
                             (res[x][y] > res[x][y - 1] && res[x][y] <= delay[x][y - 1])) ) {
                    res[x][y - 1] = min(res[x][y], delay[x][y - 1]);  tem.push_back({x, y - 1});
                }
                if (x < m - 1 && res[x + 1][y] >= 0 && (!res[x + 1][y] ||
                                 (res[x][y] > res[x + 1][y] && res[x + 1][y] <= delay[x][y])) ) {
                    res[x + 1][y] = min(res[x][y], delay[x + 1][y]);  tem.push_back({x + 1, y});
                }
                if (y < n - 1 && res[x][y + 1] >= 0 && (!res[x][y + 1] ||
                                 (res[x][y] > res[x][y + 1] && res[x][y + 1] <= delay[x][y])) ) {
                    res[x][y + 1] = min(res[x][y], delay[x][y + 1]);  tem.push_back({x, y + 1});
                }
            }
            
            bfs = tem;
        }
        // print2D(res); cout << endl;
        
        if (res[m - 1][n - 1] > 20000) return 1000000000;
        return res[m - 1][n - 1] - 1;
    }
}; 
