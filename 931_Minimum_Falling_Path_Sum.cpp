// https://leetcode.com/problems/minimum-falling-path-sum/
// DP

class Solution {
public:
    #define M matrix
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = M.size(), n = M[0].size();
        
        if (n == 1) return M[0][0];
        
        vector<vector<int> > dp(m, vector<int>(n));
        
        for (int i = 0; i < n; i++) dp[0][i] = M[0][i];
        
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int minPre = dp[i - 1][j];
                
                if (j > 0) minPre = min(minPre, dp[i - 1][j - 1]);
                if (j < n - 1) minPre = min(minPre, dp[i - 1][j + 1]);
                
                dp[i][j] = minPre + M[i][j];
            }
        }
        
        int res = dp[m - 1][0];
        for (int i = 1; i < n; i++) res = min(res, dp[m - 1][i]);
        
        return res;
    }
};
