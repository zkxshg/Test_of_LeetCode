// https://leetcode.com/problems/integer-break/
// DP

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1); dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int res = 1;
            for (int j = 1; j < i; j++)
                res = max(j * max(i - j, dp[i - j]), res);
            dp[i] = res;
        }
        
        return dp[n];
        
    }
};
