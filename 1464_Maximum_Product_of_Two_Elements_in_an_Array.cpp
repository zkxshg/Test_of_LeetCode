// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// search
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) nums[i]--;
        int m = 0;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                m = max(nums[i] * nums[j], m);
        return m;
    }
};
