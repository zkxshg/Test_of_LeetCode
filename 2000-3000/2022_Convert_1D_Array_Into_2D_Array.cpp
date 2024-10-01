// https://leetcode.com/problems/convert-1d-array-into-2d-array/description/?envType=daily-question&envId=2024-09-01
// Matrix

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int l = original.size();
        if (l != m * n) return {};

        vector<vector<int> > res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) res[i][j] = original[n * i + j];
        }

        return res;
    }
};
