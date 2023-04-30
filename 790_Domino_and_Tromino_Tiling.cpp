// https://leetcode.com/problems/domino-and-tromino-tiling/
// DP

class Solution {
public:
    #define ll long long
    ll ub = 1e9 + 7;
        
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        if (n == 4) return 11;
        
        // vector<int> fund(5);
        // fund[1] = 1; fund[2] = 1; fund[3] = 2; fund[4] = 2;
        
        vector<ll> dp(n + 1);
        dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 5; dp[4] = 11;   
        
        for (int i = 5; i <= n; i++) {
            dp[i] = (dp[i] + dp[i - 1]) % ub;
            dp[i] = (dp[i] + dp[i - 2]) % ub;
            
            for (int j = i - 3; j >= 0; j--)
                dp[i] = (dp[i] + (dp[j] * 2) % ub) % ub;
        }
        
        return dp[n];
        
    }
};
