// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// DP

class Solution {
public:
 
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        
        vector<vector<int> > dp(m, vector<int>(n));
        
        // Boundary Condition
        bool match = false;
        
        dp[0][0] = s1[0] + s2[0];
        
        int sum = s1[0] + s2[0];
        if (s1[0] == s2[0]) {
            match = true;
            dp[0][0] = 0;
            sum = 0;
        } 
        
        for (int i = 1; i < m; i++) {
            sum += s1[i];
            
            if (s1[i] == s2[0] && !match) {
                sum -= 2 * s2[0]; match = true;
            } 
            
            dp[i][0] = sum; 
        }
        
        sum = s1[0] + s2[0]; match = false;
        
        if (s1[0] == s2[0]) {
            match = true;
            sum = 0;
        } 
        
        for (int i = 1; i < n; i++) {
            sum += s2[i];
            
            if (s1[0] == s2[i] && !match) {
                sum -= 2 * s1[0]; match = true;
            } 
            
            dp[0][i] = sum; 
        }
        
        // DP
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j] + s1[i], dp[i][j - 1] + s2[j]);
                if (s1[i] == s2[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
        
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) cout << dp[i][j] << ",";
//             cout << endl;
//         } cout << endl;
        
        return dp[m - 1][n - 1];
    }
};
