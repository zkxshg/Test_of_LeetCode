// https://leetcode.com/problems/smallest-index-with-equal-value/
/ math

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int res = -1, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i % 10 == nums[i]) {
                res = i; break;
            }
        }
        return res;
    }
};a
