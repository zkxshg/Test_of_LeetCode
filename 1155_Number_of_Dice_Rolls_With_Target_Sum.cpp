// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// DP

class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) {
        if (target < n) return 0;

        vector<vector<ll> > dp(n, vector<ll>(target + 1));
        
        for (int i = 1; i <= min(target,  k); i++) dp[0][i] = 1;
        
        for (int i = 1; i < n; i++) {
            int ub = min(target, k * (i + 1));
            for (int j = i + 1; j <= ub; j++) {
                for (int k2 = 1; k2 <= k; k2++) {
                    if (j - k2 <= 0) break;
                    
                    dp[i][j] += dp[i - 1][j - k2]; dp[i][j] %= MOD;
                }
            }
            // cout << i << ":" << dp[i][target] << endl;
        }
        
        return dp[n - 1][target];
    }
};
