/ /https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// sorting

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size(); if (n < 3) return true;
        sort(arr.begin(), arr.end());
        int div = arr[1] - arr[0];
        for (int i = 2; i < n; i++) if (arr[i] - arr[i - 1] != div) return false;
        return true;
    }
};
