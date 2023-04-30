// https://leetcode.com/problems/maximum-gap/
// sort

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < n; i++) res = max(res, nums[i] - nums[i - 1]);
        return res;
    }
};
