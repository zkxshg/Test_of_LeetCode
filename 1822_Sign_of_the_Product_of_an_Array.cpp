// https://leetcode.com/problems/sign-of-the-product-of-an-array/
// math
class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool pos = true;
        for (int i : nums) {
            if (!i) return 0;
            else if (i < 0) pos = !pos;
        }
        if (pos) return 1;
        return -1;
    }
};
