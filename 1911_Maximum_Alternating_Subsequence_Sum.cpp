// https://leetcode.com/problems/maximum-alternating-subsequence-sum/
// greedy

class Solution {
public:
    #define ll long long
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size(); if (n < 2) return nums[0];
        
        ll res = 0;
        
        int pos = 0;
        while (pos < n - 1 && nums[pos + 1] >= nums[pos]) pos++;
        int st = nums[pos]; res += st;

        while (pos < n) {
            // down
            int bot = pos + 1;
            while (bot < n - 1 && nums[bot] >= nums[bot + 1]) bot++;
            
            // up
            int up = bot + 1;
            while (up < n - 1 && nums[up] <= nums[up + 1]) up++;
            
            if (up < n) res += nums[up] - nums[bot];
            
            pos = up;
        }
        
        return res;
        
    }
};
