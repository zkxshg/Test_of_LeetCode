// 1394. Find Lucky Integer in an Array
// Link: https://leetcode.com/problems/find-lucky-integer-in-an-array/
// Lang: C++
// Date: 2025-08-21 21:04:25.782 UTC

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> fre;
        for (int i : arr) fre[i]++;

        int res = -1;
        for (auto& p : fre) {
            if (p.first == p.second) res = max(res, p.first);
        }
        return res;
    }
};
