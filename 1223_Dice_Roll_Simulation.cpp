// https://leetcode.com/problems/dice-roll-simulation/
// DP

class Solution {
public:
    #define ll long long
    ll UB = 1e9 + 7;
    
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<ll> > dp(7, vector<ll>(n));
        
        for (int i = 0; i < 6; i++) dp[i][0] = 1; dp[6][0] = 6;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                
                if (i >= rollMax[j]) {
                    for (int k = 1; k <= rollMax[j]; k++) 
                        dp[j][i] = (dp[j][i] + dp[6][i - k] - dp[j][i - k]) % UB;
                    if (dp[j][i] < 0) dp[j][i] += UB;
                }
                else dp[j][i] = dp[6][i - 1];
                
                dp[6][i] = (dp[6][i] + dp[j][i]) % UB;
            }
        }
      
        return dp[6][n - 1];
    }
};
