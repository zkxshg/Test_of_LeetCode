// https://leetcode.com/problems/matrix-diagonal-sum/
// math

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), res = 0;
        for (int i = 0; i < n; i++) {
            res += mat[i][i];
            if (i != n - 1 - i) res += mat[i][n - 1 - i];
        }
        return res;
    }
};
