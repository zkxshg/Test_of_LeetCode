// https://leetcode.com/problems/tallest-billboard/description/
// DP

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, -1));
        dp[0][sum] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int diff = -sum; diff <= sum; ++diff) {
                if (dp[i - 1][diff + sum] == -1) continue;
                int idx = diff + sum;
                dp[i][idx] = max(dp[i][idx], dp[i - 1][idx]);
                dp[i][idx + rods[i - 1]] = max(dp[i][idx + rods[i - 1]], dp[i - 1][idx] + rods[i - 1]);
                dp[i][idx - rods[i - 1]] = max(dp[i][idx - rods[i - 1]], dp[i - 1][idx]);
            }
        }

        return dp[n][sum];
    }
};
