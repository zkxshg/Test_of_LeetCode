// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// DP

class Solution {
public:
    #define JD jobDifficulty
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = JD.size();
        
        if (d > n) return -1;
        if (d == n) {
            int sum = 0; for (int i : JD) sum += i; return sum;
        }
            
        vector<vector<int> > preSum(n, vector<int>(n));
        for (int i = 0; i < n; i++) preSum[i][i] = JD[i];
        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) preSum[i][j] = max(JD[j], preSum[i][j - 1]);
        
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) cout << preSum[i][j] << ",";
        //     cout << endl;
        // }
        
        vector<vector<int> > dp(d, vector<int>(n, 300001));
        
        int maxAll = preSum[0][n - 1];
        if (d < 2) return maxAll;
        
        for (int i = 1; i < n; i++) dp[1][i] = preSum[0][i - 1] + preSum[i][n - 1];
        
        for (int i = 2; i < d; i++) {
            for (int j = i; j < n; j++) {
                dp[i][j] = (i + 1) * maxAll;
                
                for (int k = j - 1; k >= 1; k--) 
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(preSum[k][j - 1], preSum[j][n - 1]));
            }
        }
        
        int res = d * maxAll;
        for (int i = 0; i < n; i++) res = min(res, dp[d - 1][i]);
        return res;
    }
};
