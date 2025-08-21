// https://leetcode.com/problems/2-keys-keyboard/
// DP

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 9999); dp[1] = 0;
        for (int i = 2; i <= n; i++) 
            for (int j = i - 1; j >= 1; j--)
                if ((i - j) % j == 0) dp[i] = min(dp[i], dp[j] + 1 + (i - j) / j);
        return dp[n];
    }
};
