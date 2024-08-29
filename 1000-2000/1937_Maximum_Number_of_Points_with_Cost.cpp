// https://leetcode.com/problems/maximum-number-of-points-with-cost/?envType=daily-question&envId=2024-08-17
// DP

class Solution {
public:
    #define ll long long
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        
        vector<ll> dp(n);
        for (int j = 0; j < n; j++) dp[j] = points[0][j];
        
        for (int i = 1; i < m; i++) {
            vector<ll> nex(n);

            vector<ll> maxLeft(n, LLONG_MIN), maxRight(n, LLONG_MIN);

            maxLeft[0] = dp[0];
            for (int j = 1; j < n; j++) maxLeft[j] = max(maxLeft[j - 1] - 1, dp[j]);

            maxRight[n - 1] = dp[n - 1];
            for (int j = n - 2; j >= 0; j--) maxRight[j] = max(maxRight[j + 1] - 1, dp[j]);

            for (int j = 0; j < n; j++) nex[j] = points[i][j] + max(maxLeft[j], maxRight[j]);
            
            dp = nex;
        }
        
        ll res = LLONG_MIN;
        for (int j = 0; j < n; j++) res = max(res, dp[j]);
        
        return res;
    }
};  
