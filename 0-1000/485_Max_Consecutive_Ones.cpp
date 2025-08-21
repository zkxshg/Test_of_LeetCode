// https://leetcode.com/problems/max-consecutive-ones/
// array

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, res = 0;
        for (int i : nums) {
            if (i) {
                count++; res = max(res, count);
            }
            else count = 0;
        }
        return res;
    }
};
