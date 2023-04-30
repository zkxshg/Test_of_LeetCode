// https://leetcode.com/problems/burst-balloons/
// dp

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 2) return nums[0];
        
        vector<vector<int> > dp(n + 2, vector<int>(n + 2));
        
        vector<int> bn(n + 2, 1);
        for (int i = 1; i <= n; i++) bn[i] = nums[i - 1];
        
        for (int l = 3; l <= n + 2; l++) {
            for (int i = 0; i <= n + 2 - l; i++) {
                int j = i + l - 1;
                for (int k = i + 1; k < j; k++) 
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + bn[i] * bn[j] * bn[k]);
            }
        }
        
        return dp[0][n + 1];
    }
};
