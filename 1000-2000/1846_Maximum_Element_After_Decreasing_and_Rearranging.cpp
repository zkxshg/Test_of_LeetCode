// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/
// sorting

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size(), res = 0;
        sort(arr.begin(), arr.end());

        for (int i : arr) {
            if (i > res) res++;
        }

        return res;
    }
};
