// 2419. Longest Subarray With Maximum Bitwise AND
// Link: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
// Lang: C++
// Date: 2025-08-21 20:53:07.721 UTC

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
