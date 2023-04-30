// https://leetcode.com/problems/maximum-difference-between-increasing-elements/
// array

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minV = nums[0], res = -1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > minV) res = max(res, nums[i] - minV);
            else minV = nums[i];
        }
        return res;
    }
};
