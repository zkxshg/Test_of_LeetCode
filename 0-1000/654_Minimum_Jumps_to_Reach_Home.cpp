// https://leetcode.com/problems/minimum-jumps-to-reach-home/
// BFS

class Solution {
public:
    int ub = 1e5;
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) { 
        vector<int> dp(ub, 0);
        
        for (int f : forbidden) dp[f] = -1; dp[0] = 1;
        
        vector<int> forw; forw.push_back(0);
        vector<int> back;
        
        while (!forw.empty() || !back.empty()) {
            vector<int> tforw;
            vector<int> tback;
            
            for (int pos : forw) {
                if (pos - b > 0 && dp[pos - b] >= 0 && !dp[pos - b]) {
                    dp[pos - b] = dp[pos] + 1; tback.push_back(pos - b);
                }
                
                if (pos + a < ub && dp[pos + a] >= 0 && !dp[pos + a]) {
                    dp[pos + a] = dp[pos] + 1; tforw.push_back(pos + a);
                }
            }
            
            for (int pos : tback) {
                if (pos + a < ub && dp[pos + a] >= 0 && !dp[pos + a]) {
                    dp[pos + a] = dp[pos] + 1; tforw.push_back(pos + a);
                }
            }
            
            back = tback; forw = tforw;
        }
        
        return dp[x] - 1;
    }
};
