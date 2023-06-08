// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
// binary search

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int res = 0;
        for (int i = 0; i < m; i++) {
            int lb = lower_bound(grid[i].rbegin(), grid[i].rend(), 0) - grid[i].rbegin();
            res += lb;
        }

        return res;
    }
};
