// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Mask
class Solution {
public:
    #define M matrix
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = M.size(), n = M[0].size();
        
        int res = 1;
        vector<vector<int> > mlen(m, vector<int>(n, 1));
        
        vector<int> cand;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = i, y = j;
                
                if (x > 0 && mlen[x-1][y] <= 1 && M[x-1][y] > M[x][y]) {
                    mlen[x-1][y] = 2; cand.push_back((x-1)*200 + y);
                }
                
                if (y > 0 && mlen[x][y-1] <= 1 && M[x][y-1] > M[x][y]) {
                    mlen[x][y-1] = 2; cand.push_back((x)*200 + y-1);
                }
                
                if (x < m - 1 && mlen[x+1][y] <= 1 && M[x+1][y] > M[x][y]) {
                    mlen[x+1][y] = 2; cand.push_back((x+1)*200 + y);
                }
                
                if (y < n - 1 && mlen[x][y+1] <= 1 && M[x][y+1] > M[x][y]) {
                    mlen[x][y+1] = 2; cand.push_back((x)*200 + y+1);
                }
            }
        }
        
        if (cand.empty()) return 1;
        
        res = 2;
        while (!cand.empty()) {
            vector<int> temC;
            
            for (int v : cand) {
                int x = v / 200, y = v % 200;
                
                if (x > 0 && mlen[x-1][y] <= res && M[x-1][y] > M[x][y]) {
                    mlen[x-1][y] = res + 1; temC.push_back((x-1)*200 + y);
                }
                
                if (y > 0 && mlen[x][y-1] <= res && M[x][y-1] > M[x][y]) {
                    mlen[x][y-1] = res + 1; temC.push_back((x)*200 + y-1);
                }
                
                if (x < m - 1 && mlen[x+1][y] <= res && M[x+1][y] > M[x][y]) {
                    mlen[x+1][y] = res + 1; temC.push_back((x+1)*200 + y);
                }
                
                if (y < n - 1 && mlen[x][y+1] <= res && M[x][y+1] > M[x][y]) {
                    mlen[x][y+1] = res + 1; temC.push_back((x)*200 + y+1);
                }
            }
            
            if (!temC.empty()) res++;
            cand = temC;
        }
        
        return res;
    }
};

// BFS
class Solution {
public:
    #define M matrix
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = M.size(), n = M[0].size();
        
        int res = 1;
        
        vector<vector<int> > cand; 
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                cand.push_back({i * 200 + j});
        
        while (!cand.empty()) {
            vector<vector<int> > temC;
            
            for (vector<int> v : cand) {
                int ep = v.back();
                int x = ep / 200, y = ep % 200;
                
                if (x > 0 && M[x-1][y] > M[x][y] && find(v.begin(), v.end(), (x-1)*200 + y) == v.end()) {
                    vector<int> tem(v.begin(), v.end()); tem.push_back((x-1)*200 + y); temC.push_back(tem);
                }
                
                if (y > 0 && M[x][y-1] > M[x][y] && find(v.begin(), v.end(), (x)*200 + y-1) == v.end()) {
                    vector<int> tem(v.begin(), v.end()); tem.push_back((x)*200 + y-1); temC.push_back(tem);
                }
                
                if (x < m - 1 && M[x+1][y] > M[x][y] && find(v.begin(), v.end(), (x+1)*200 + y) == v.end()) {
                    vector<int> tem(v.begin(), v.end()); tem.push_back((x+1)*200 + y); temC.push_back(tem);
                }
                
                if (y < n - 1 && M[x][y+1] > M[x][y] && find(v.begin(), v.end(), (x)*200 + y+1) == v.end()) {
                    vector<int> tem(v.begin(), v.end()); tem.push_back((x)*200 + y+1); temC.push_back(tem);
                }
            }
            
            if (!temC.empty()) res++;
            cand = temC;
        }
        
        return res;
    }
};
