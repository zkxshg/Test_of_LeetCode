// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
// array

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 0, lb = 1;
        for (int i : nums) {
            res += i; lb = min(lb, res);
        }
        if (lb > 0) return 1;
        return -lb + 1;
    }
};
