// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
// Greedy + Sorting

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // neg neg
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0 || k < 1) break;
            nums[i] = -nums[i]; k--;
        }
        // neg min-pos
        if (!k || !(k % 2)) return accumulate(nums.begin(), nums.end(), 0);
        
        sort(nums.begin(), nums.end());
        nums[0] = -nums[0];
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
