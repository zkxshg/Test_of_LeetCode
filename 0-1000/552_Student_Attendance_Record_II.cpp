// https://leetcode.com/problems/student-attendance-record-ii/?envType=daily-question&envId=2024-05-26
// DP

class Solution {
public:
    #define ll long long
    int checkRecord(int n) {
        const int MOD = 1000000007;
        vector<vector<ll>> dp(6, vector<ll>(n + 1, 0));
        
        // Initialize base cases
        dp[0][0] = 1; // 0A0L
        dp[1][0] = 0; // 0A1L
        dp[3][0] = 0; // 1A0L
        
        for (int i = 1; i <= n; ++i) {
            // Transition rules
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % MOD; // 0A0L
            dp[1][i] = dp[0][i - 1]; // 0A1L
            dp[2][i] = dp[1][i - 1]; // 0A2L
            dp[3][i] = (dp[3][i - 1] + dp[4][i - 1] + dp[5][i - 1] + dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % MOD; // 1A0L
            dp[4][i] = dp[3][i - 1]; // 1A1L
            dp[5][i] = dp[4][i - 1]; // 1A2L
        }
        
        // Sum up the possibilities
        long long ans = 0;
        for (int i = 0; i < 6; ++i) {
            ans = (ans + dp[i][n]) % MOD;
        }
        
        return static_cast<int>(ans);
    }
};
