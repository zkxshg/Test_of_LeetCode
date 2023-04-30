// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
// greedy
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size(), res = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] <= nums[i - 1]) {
                res += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return res;
    }
};
