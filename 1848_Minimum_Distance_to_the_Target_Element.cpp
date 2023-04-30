// https://leetcode.com/problems/minimum-distance-to-the-target-element/
// array

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size(), res = n;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) res = min(res, abs(i - start));
            if (i - start > res) break;
        }
        return res;
    }
};
