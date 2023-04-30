// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
// dp

class Solution {
public:
    #define ll long long

    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        ll res = 0;

        vector<int> dp(n); 
        if (nums[0] == 0) {
            dp[0] = 1; res++;
        }

        for(int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                dp[i] = dp[i - 1] + 1;
                res += dp[i];
            }
        }

        return res;        
    }
};
