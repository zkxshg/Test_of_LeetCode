// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/?envType=daily-question&envId=2024-08-11
// DFS

class Solution {
public:
    int minCon, zeroNum;
    
    void dfs(int x, int y, int num, vector<vector<int>>& grid, vector<vector<int>>& land) {
        int m = grid.size(), n = grid[0].size();
        land[x][y] = num;

        int conNum = 0;

        if (x > 0 && grid[x - 1][y]) {
            conNum++;
            if (!land[x - 1][y]) dfs(x - 1, y, num, grid, land);
        }

        if (y > 0 && grid[x][y - 1]) {
            conNum++;
            if (!land[x][y - 1]) dfs(x, y - 1, num, grid, land);
        }

        if (x < m - 1 && grid[x + 1][y]) {
            conNum++;
            if (!land[x + 1][y]) dfs(x + 1, y, num, grid, land);
        }

        if (y < n - 1 && grid[x][y + 1]) {
            conNum++;
            if (!land[x][y + 1]) dfs(x, y + 1, num, grid, land);
        }

        minCon = min(minCon, conNum);
    }

    int islandNum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int> > island(m, vector<int>(n));

        int landNum = 0;
        for (int i = 0; i < m; i++) { 
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !island[i][j]) {
                    landNum++;
                    dfs(i, j, landNum, grid, island);
                }
            }
        }

        return landNum;
    }

    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int landNum = islandNum(grid);

        if (landNum == 0 || landNum > 1) return 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;

                grid[i][j] = 0;

                if (islandNum(grid) != 1) return 1;

                grid[i][j] = 1;
            }
        }

        return 2;
    }
};
