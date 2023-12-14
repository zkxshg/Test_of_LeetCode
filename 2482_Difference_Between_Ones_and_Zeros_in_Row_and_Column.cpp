// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/
// Array

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow(m, 0);
        vector<int> onesCol(n, 0);

        // Calculate onesRow and onesCol arrays.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }

        vector<std::vector<int>> diff(m, std::vector<int>(n, 0));

        // Populate the difference matrix.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int zerosRow = n - onesRow[i];
                int zerosCol = m - onesCol[j];

                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow - zerosCol;
            }
        }

        return diff;
    }
};
