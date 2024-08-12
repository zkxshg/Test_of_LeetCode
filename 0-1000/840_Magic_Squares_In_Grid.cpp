// https://leetcode.com/problems/magic-squares-in-grid/?envType=daily-question&envId=2024-08-09
// Matrix + Hash table

class Solution {
public:
    bool isMagicSquare(const vector<vector<int>>& grid, int r, int c) {
        unordered_set<int> numbers;
        int sum = 0;

        // Check if all numbers from 1 to 9 are present and compute the sums
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || !numbers.insert(num).second) {
                    return false;
                }
            }
        }

        // Check sums of rows, columns and diagonals
        int row1 = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        int row2 = grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2];
        int row3 = grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2];
        int col1 = grid[r][c] + grid[r + 1][c] + grid[r + 2][c];
        int col2 = grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1];
        int col3 = grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2];
        int diag1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int diag2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];

        return (row1 == row2 && row2 == row3 && row3 == col1 && col1 == col2 && col2 == col3 && col3 == diag1 && diag1 == diag2 && diag2 == 15);
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        // Check each possible 3x3 subgrid
        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
