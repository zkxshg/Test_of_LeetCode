// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
// sorting

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) == k) res++;
                else if (abs(nums[i] - nums[j]) > k) break;
            }
        }
        return res;
    }
};
