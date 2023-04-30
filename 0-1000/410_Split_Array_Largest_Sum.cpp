// https://leetcode.com/problems/split-array-largest-sum/
// dp (O(m * n * n) in time and O(m * n) in space) + greedy

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        
        vector<vector<int> > dp(m, vector<int>(n, INT_MAX));
        
        vector<int> pre(n); pre[0] = nums[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + nums[i];
        
        for (int i = 0; i < n; i++) dp[0][i] = pre[i];
        
        for (int lv = 1; lv < m; lv++) {
            
            for (int i = lv; i < n; i++) {
                
                int minV = INT_MAX;
                
                for (int j = i - 1; j >= lv - 1; j--) 
                    minV = min(minV, max(dp[lv - 1][j], pre[i] - pre[j]));
                
                dp[lv][i] = minV;
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
