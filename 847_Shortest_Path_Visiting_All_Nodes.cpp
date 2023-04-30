// https://leetcode.com/problems/shortest-path-visiting-all-nodes/
// dp + bit mask + dp

class Solution {
public:
    vector<vector<int>> dis;
    
    void floyd(int n) {
        for (int k = 0; k < n; k++) 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
        
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        // update distance
        dis.resize(n, vector<int>(n, 0x3f3f3f3f));
        
        for (int i = 0; i < n; i++) 
            for (int j : graph[i]) {
                dis[i][j] = 1; dis[j][i] = 1;
            }      
        
        floyd(n);
        
        // DP
        vector<vector<int>> dp((1<<n), vector<int>(n, 0x3f3f3f3f));
        
        for (int i = 0; i < n; i++) dp[1<<i][i] = 0;
        
        for (int g = 1; g < (1<<n); g++) {
            for (int i = 0; i < n; i++) {
                int src = (1<<i);
                
                if (g & src) {
                    for (int j = 0; j < n; j++) {
                        int dst = (1<<j);
                        
                        if (!(g & dst)) dp[g|dst][j] = min(dp[g|dst][j], dp[g][i] + dis[i][j]);
                    }
                }
            }
        }
        
        int res = INT_MAX;
        // for (int i : dp[(1<<n) - 1]) cout << i << endl;
        for (int i = 0; i < n; i++) res = min(res, dp[(1<<n) - 1][i]);
        
        return res;
    }
};
