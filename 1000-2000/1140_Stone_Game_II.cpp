// https://leetcode.com/problems/stone-game-ii/description/
// DFS
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + piles[i];

        // Fixing the dimensions of the dp vector
        vector<vector<vector<int>>> dp(2 * n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

        function<int(int, int, int)> dfs = [&](int x, int l, int r) {
            if (l > r) return 0;
            if (dp[x][l][r] != 0) return dp[x][l][r];
            
            int mx = INT_MIN;
            for (int i = 1; i <= 2 * x && l + i - 1 <= r; i++) {
                int stones = pre[l + i] - pre[l];
                int next_x = max(x, i);
                mx = max(mx, stones - dfs(next_x, l + i, r));
            }
            dp[x][l][r] = mx;
            return mx;
        };

        int total_stones = pre[n] - pre[0];
        int diff = dfs(1, 0, n - 1);

        return (total_stones + diff) / 2;
    }
};

// DP
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + piles[i];

        vector< vector< vector<int>>> dp(n + 1, vector(n, vector<int>(n)));

        for(int l = 1; l <= n; l++) {

            for(int i = n - l; i >= 0; i--) {
                int j = i + l - 1;

                for(int x = 1; x <= n; x++) {

                    if (l <= x) dp[x][i][j] = pre[i + l] - pre[i];
                    else {
                        int stones = pre[i + x] - pre[i], left = pre[i + l] - pre[i + x + 1];
                        
                        for (int m = 1; m <= n && m <= 2 * x; m++)
                            dp[x][i][j] = max(dp[x][i][j],
                                stones + left - dp[m][i + x][j]);
                    }
                }
            }
        }

        return max(dp[1][0][n - 1], dp[2][0][n - 1]);
        
    }
};
