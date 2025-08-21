// 3201. Find the Maximum Length of Valid Subsequence I
// Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/
// Lang: C++
// Date: 2025-08-21 21:01:35.611 UTC

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int> > dp(n,  vector<int>(2));
        if (nums[0] % 2) dp[0][1] = 1;
        else dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] % 2) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + 1);
            }
            else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = dp[i - 1][1];
            }
        }
        
        int res = max(dp[n - 1][0], dp[n - 1][1]);

        vector<vector<int> > dp2(n,  vector<int>(2));
        if (nums[0] % 2) dp2[0][1] = 1;
        else dp2[0][0] = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] % 2) {
                dp2[i][0] = dp2[i - 1][0];
                dp2[i][1] = dp2[i - 1][1] + 1;
            }
            else {
                dp2[i][0] = dp2[i - 1][0] + 1;
                dp2[i][1] = dp2[i - 1][1];
            }
        }

        int res2 = max(dp2[n - 1][0], dp2[n - 1][1]);
        return max(res, res2);
    }

};
