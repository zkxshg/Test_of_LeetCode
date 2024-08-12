// https://leetcode.com/problems/spiral-matrix-iii/?envType=daily-question&envId=2024-08-08
// Matrix + Array

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int dir = 0; 
        int steps = 1;

        int r = rStart, c = cStart;
        res.push_back({r, c});
        while (res.size() < rows * cols) {
            for (int i = 0; i < steps; ++i) {
                r += directions[dir][0];
                c += directions[dir][1];
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    res.push_back({r, c});
                }
            }
            dir = (dir + 1) % 4; // Change direction
            if (dir % 2 == 0) steps++; // Increase steps after completing a full circle
        }

        return res;
    }
};
