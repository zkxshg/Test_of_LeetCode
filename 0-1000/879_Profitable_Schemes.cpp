// https://leetcode.com/problems/profitable-schemes/
// DP

class Solution {
public:
    #define ll long long
    int ub = 1e9 + 7;    

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int l = group.size();

        vector< vector< vector<int>>> dp(l + 1, 
            vector<vector<int>>(n + 1, vector<int>(minProfit, 1)));
        for (int p = 0; p < minProfit; p++) {
            for (int num = 0; num <= n; num++) {
                for (int i = 1; i <= l; i++) {
                    dp[i][num][p] = dp[i - 1][num][p];

                    int c = i - 1, cNum = group[c], cPro = profit[c];
                    if (num < cNum || p < cPro) continue;

                    int pre = dp[i - 1][num - cNum][p - cPro];
                    dp[i][num][p] = (pre + dp[i - 1][num][p]) % ub; 
                }
            }
        }

        
        vector<vector<int> > dp2(l + 1, vector<int>(n + 1, 1));
        for (int num = 0; num <= n; num++) {
            for (int i = 1; i <= l; i++) {
                dp2[i][num] = dp2[i - 1][num];

                int c = i - 1, cNum = group[c];
                if (num < cNum) continue;

                int pre = dp2[i - 1][num - cNum];
                dp2[i][num] = (dp2[i - 1][num] + pre) % ub; 
            }
        }

        
        if (minProfit < 1) return dp2[l][n];


        if (dp2[l][n] < dp[l][n][minProfit - 1]) 
            return dp2[l][n] - dp[l][n][minProfit - 1] + ub;

        return dp2[l][n] - dp[l][n][minProfit - 1];
    }
}; 
