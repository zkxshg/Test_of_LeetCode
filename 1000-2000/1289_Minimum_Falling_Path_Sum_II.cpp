// https://leetcode.com/problems/minimum-falling-path-sum-ii/?envType=daily-question&envId=2024-04-26
// DP

class Solution {
public:
    #define pii pair<int, int>

    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int res = 0;
        if (n < 2) {
            for (int i = 0; i < m; i++) res += grid[i][0];
            return res;
        }

        // dp[i][j]表示选取第i行第j列元素时，到当前行为止的最小下降路径和
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        // 初始化第一行
        for (int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }

        // 填充dp表
        for (int i = 1; i < m; i++) {
            // 为了处理列的选择冲突，我们需要先找到上一行的最小值
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != k) {  // 保证不在同一列
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + grid[i][j]);
                    }
                }
            }
        }

        // 从最后一行找到最小的下降路径和
        res = INT_MAX;
        for (int j = 0; j < n; j++) {
            res = min(res, dp[m-1][j]);
        }
        return res;
    }
};
