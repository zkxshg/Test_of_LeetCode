// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/
// DP

class Solution {
public:
    const int MOD = 1e9 + 7;

    static bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<0>(a) > get<0>(b);
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<tuple<int, int, int> > tuples;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                tuples.push_back({grid[i][j], i, j});

        sort(tuples.begin(), tuples.end(), cmp);
        // for (auto& [val, x, y] : tuples) cout << val << ","; cout << endl;

        vector<vector<int>> dp(m, vector<int>(n, 1));

        int directions[] = {-1, 0, 1, 0, -1};
        for (auto& [val, x, y] : tuples) {
            for (int i = 0; i < 4; ++i) {
                int newX = x + directions[i], newY = y + directions[i + 1];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    grid[newX][newY] < grid[x][y]) {

                    dp[newX][newY] += dp[x][y];
                    dp[newX][newY] %= MOD;
                }
            }
        }

        int result = 0;
        for (const auto& row : dp) {
            for (int val : row) {
                result += val;
                result %= MOD;
            }
        }

        return result;
    }
};
