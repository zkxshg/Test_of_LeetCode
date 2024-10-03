// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/?envType=daily-question&envId=2024-09-01
// Bit Manipulation

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxN =  *max_element(nums.begin(),nums.end());

        int st = 0, en = 0, res = 1;
        while (en < n) {
            if (nums[en] == maxN) res = max(res, en - st + 1);
            else st = en + 1;

            en++;
        }

        return res;
    }
};
