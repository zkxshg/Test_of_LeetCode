// 3202. Find the Maximum Length of Valid Subsequence II
// Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/
// Lang: C++
// Date: 2025-08-21 21:01:13.765 UTC

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 1;
        
        vector<vector<int>> dp(n, vector<int>(k, 1));

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;
                dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
                result = max(result, dp[i][mod]);
            }
        }

        return result;
    }
};
