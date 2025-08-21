// https://leetcode.com/problems/path-with-minimum-effort/
// Dijkstra

class Solution {
public:
    #define H heights
    
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }    
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = H.size(), n = H[0].size();
        
        if (m < 2 && n < 2) return 0;
        
        vector<int> dst(m * 100 + n, -1);
        
        unordered_map<int, unordered_map<int, int> > path;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // path[i * 100 + j][i * 100 + j] = INT_MAX;
                if (i > 0) path[i * 100 + j][(i - 1) * 100 + j] = abs(H[i][j] - H[i - 1][j]);
                if (j > 0) path[i * 100 + j][i * 100 + (j - 1)] = abs(H[i][j] - H[i][j - 1]);
                if (i < m-1) path[i * 100 + j][(i + 1) * 100 + j] = abs(H[i][j] - H[i + 1][j]);
                if (j < n-1) path[i * 100 + j][i * 100 + (j + 1)] = abs(H[i][j] - H[i][j + 1]);
            }
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> nodes;
        nodes.push({0, 0});
        
        while (!nodes.empty()) {
            int N = nodes.top().first; nodes.pop();
            // cout << N << endl;
            
            for (auto& p : path[N]) {
                int v = p.first, d = p.second;
                // cout << v << ":" << d << endl;
                
                if (dst[v] < 0 || dst[v] > max(d, dst[N])) {
                    dst[v] = max(d, dst[N]);
                    nodes.push(make_pair(v, dst[v]));
                    // cout << v << ":" << dst[v] << endl;
                }  
            }
        }
        
        return dst[(m - 1) * 100 + n - 1];
    }
};
