// https://leetcode.com/problems/longest-arithmetic-subsequence/description/
// DP

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int> > dp(n, vector<int>(501, 1));
        vector<vector<int> > neg_dp(n, vector<int>(501, 1));

        int res = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int div = nums[i] - nums[j];
                if (div >= 0) {
                    dp[i][div] = max(dp[j][div] + 1, dp[i][div]);
                    res = max(res, dp[i][div]);
                }
                else {
                    neg_dp[i][-div] = max(neg_dp[j][-div] + 1, neg_dp[i][-div]);
                    res = max(res, neg_dp[i][-div]);
                }
            }
        }
        
        return res;
    }
};
