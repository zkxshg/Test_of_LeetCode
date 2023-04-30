// https://leetcode.com/problems/range-addition-ii/
// math

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int maxM = m, maxN = n;
        for (auto& v : ops) {
            m = min(m, v[0]); n = min(n, v[1]);
        }
        return m * n;
    }
};
