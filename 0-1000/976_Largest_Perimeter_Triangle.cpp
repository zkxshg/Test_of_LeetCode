// https://leetcode.com/problems/largest-perimeter-triangle/
// math

class Solution {
public:
    
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for (int i = n - 1; i >= 2; i--)
            if (nums[i - 1] + nums[i - 2] > nums[i])
                res = max(res, nums[i] + nums[i - 1] + nums[i - 2]);
        
        return res;
    }
};
