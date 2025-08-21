// 2210. Count Hills and Valleys in an Array
// Link: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
// Lang: C++
// Date: 2025-08-21 20:54:02.191 UTC

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), st = 1, en = 1, res = 0;

        while (st < n && en < n) {
            while (en < n - 1 && nums[st] == nums[en + 1]) en++;
            if (en >= n - 1) break;

            if (nums[st] > nums[st - 1] && nums[en] > nums[en + 1]) res++;
            else if (nums[st] < nums[st - 1] && nums[en] < nums[en + 1]) res++;

            st = en + 1; en = st;
        }

        return res;
    }
};
