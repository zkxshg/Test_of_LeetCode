// https://leetcode.com/problems/paint-house-iii/
// DP

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int r = target;
        
        vector<vector<vector<int> > > dp(m, vector<vector<int>>(n, vector<int>(r + 1, -1)));
        
        if (!houses[0]) {
            for (int j = 0; j < n; j++) dp[0][j][1] = cost[0][j];
        }
        else dp[0][houses[0] - 1][1] = 0;
        
        for (int i = 1; i < m; i++) {
            if (!houses[i]) {
                for (int j = 0; j < n; j++) {
                    int c = cost[i][j]; 
                    // cout << "cost[" << i << "]" << "[" << j << "] = " << c << endl; 
                    
                    for (int k = 1; k <= min(i + 1, r); k++) {
                        int minV = INT_MAX; 
                        for (int j2 = 0; j2 < n; j2++) {
                            if (j2 == j) {
                                if (dp[i - 1][j2][k] >= 0) minV = min(minV, dp[i - 1][j2][k] + c);
                            } 
                            else if (dp[i - 1][j2][k - 1] >= 0) 
                                minV = min(minV, dp[i - 1][j2][k - 1] + c);
                        }
                        
                        if (minV < INT_MAX) dp[i][j][k] = minV;
                        else dp[i][j][k] = -1;
                    }
                }
            }
            else {
                int j0 = houses[i] - 1;
                for (int k = 1; k <= min(i + 1, r); k++) {
                    int minV = INT_MAX;

                    for (int j2 = 0; j2 < n; j2++) {
                        if (j2 == j0) {
                            if (dp[i - 1][j2][k] >= 0) minV = min(minV, dp[i - 1][j2][k]);
                        } 
                        else if (dp[i - 1][j2][k - 1] >= 0) minV = min(minV, dp[i - 1][j2][k - 1]);
                    }

                    if (minV < INT_MAX) dp[i][j0][k] = minV;
                    else dp[i][j0][k] = -1;
                }
            }
            
            // for (int j = 0; j < n; j++) cout << dp[i][j][r] << ","; cout << endl;
        }
                         
        int res = INT_MAX;
        for (int i = 0; i < n; i++) if (dp[m - 1][i][r] >= 0) res = min(res, dp[m - 1][i][r]);
        
        if (res >= INT_MAX) return -1;
        return res;
    }
};
