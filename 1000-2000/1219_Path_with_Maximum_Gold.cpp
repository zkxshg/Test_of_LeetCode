// https://leetcode.com/problems/path-with-maximum-gold/?envType=daily-question&envId=2024-05-14
// Backtracking

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 0;
        }

        int maxGold = 0;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

        int nodeVal = grid[x][y];
        grid[x][y] = 0; // mark as visited
        for (int i = 0; i < 4; ++i) {
            maxGold = max(maxGold, nodeVal + dfs(grid, x + dx[i], y + dy[i]));
        }

        grid[x][y] = nodeVal; // restore the value

        return maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int maxGold = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }

        return maxGold;   
    }
};
