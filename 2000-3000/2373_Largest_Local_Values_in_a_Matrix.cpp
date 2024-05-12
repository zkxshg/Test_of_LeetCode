// https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12
// array

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> res(n - 2, vector<int>(n - 2));

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {

                int tem = 0;
                for (int k = i - 1; k < i + 2; k++) {
                    for (int l = j - 1; l < j + 2; l++) {
                        tem = max(tem, grid[k][l]);
                    }
                }
                res[i - 1][j - 1] = tem;
            }
        }

        return res;
    }
};
