// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
// DP

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0); cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int len = cuts.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));

        for (int l = 2; l < len; l++) {

            for (int i = 0; i + l < len; i++) {
                int j = i + l;
                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++) 
                    dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
            }
        }

        return dp[0][len - 1];
    }
};
