// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
// math

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> fre;

        for (int i : nums) fre[i]++;

        int res = 0;
        for (auto& p : fre) {
            if (p.second == 1) return -1;

            if (p.second % 3 == 0) res += (p.second / 3);
            else res += (p.second / 3 + 1);
        }

        return res;
    }
};
