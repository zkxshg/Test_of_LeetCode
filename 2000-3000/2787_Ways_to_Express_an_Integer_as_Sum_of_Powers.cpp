// 2787. Ways to Express an Integer as Sum of Powers
// Link: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/
// Lang: C++
// Date: 2025-08-21 20:50:11.968 UTC

class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;

        // Precompute i^x for all i with i^x <= n (use integer power to avoid FP issues)
        vector<int> pw;
        for (int i = 1; ; ++i) {
            long long v = 1;
            for (int t = 0; t < x; ++t) {
                v *= i;
                if (v > n) break;
            }
            if (v > n) break;
            pw.push_back((int)v);
        }

        int m = (int)pw.size();
        // dp[i][s]: using first i powers (pw[0..i-1]), ways to sum to s
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= m; ++i) {
            int v = pw[i - 1];
            for (int s = 0; s <= n; ++s) {
                // Not take i
                int ways = dp[i - 1][s];
                // Take i if possible
                if (s >= v) {
                    ways += dp[i - 1][s - v];
                    if (ways >= MOD) ways -= MOD;
                }
                dp[i][s] = ways;
            }
        }
        return dp[m][n];
        
    }
};
