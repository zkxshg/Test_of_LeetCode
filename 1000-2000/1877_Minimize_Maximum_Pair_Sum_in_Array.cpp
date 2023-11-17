// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// sorting + greedy

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; i++) {
            res = max(res, nums[i] + nums[n - 1 - i]);
        }
        return res;
    }
};
