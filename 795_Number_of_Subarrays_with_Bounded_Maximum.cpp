// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
// DP

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        
        vector<int> N(n, 0); int st = -1;
        if (nums[0] >= left && nums[0] <= right) N[0] = 1;
        if (nums[0] <= right) st = 0;
        
        for (int i = 1; i < n; i++) {
            int t = nums[i]; 
            
            if (t > right) st = -1;
            else if (t >= left) {
                if (st < 0) {
                    st = i; N[i] = 1; 
                }
                else N[i] = i - st + 1; 
            }
            else {
                N[i] = N[i - 1]; 
                if (st < 0) st = i;
            }
        }
        
        int res = 0; for (int i : N) res += i;
        return res;
        
    }
};
