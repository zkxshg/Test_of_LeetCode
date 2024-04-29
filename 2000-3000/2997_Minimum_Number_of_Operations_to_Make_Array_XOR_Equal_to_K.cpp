// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/?envType=daily-question&envId=2024-04-29
// Bit maniputation

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xn = 0;
        for (int num : nums) {
            xn ^= num;
        }
        
        int res = 0;
        while (xn != 0 || k != 0) {
            if ((xn & 1) != (k & 1)) {
                res++;
            }
            xn >>= 1;
            k >>= 1;
        }
        
        return res; 
    }
};
