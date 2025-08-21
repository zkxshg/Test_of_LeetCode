// https://leetcode.com/problems/wildcard-matching/submissions/
// dp

class Solution {
public:
    
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        if (!n) {
            if (!m) return true;
            else return false;
        }
        
        if (!m) {
            for (char c : p)
                if (c != '*') return false;
            return true;
        }
            
        vector<vector<int> > dp(m, vector<int>(n));
        
        if (s[0] == p[0] || p[0] == '*' || p[0] == '?') dp[0][0] = 1;
        else return false;
        
        if (p[0] == '*') {
            for (int i = 0; i < m; i++)
                dp[i][0] = 1;
            
            int pos = 0;
            
            while (pos < n && p[pos] == '*') {
                dp[0][pos] = 1; pos++;
            }
            
            if (pos < n && (p[pos] == s[0] || p[pos] == '?')) {
                dp[0][pos] = 1; pos++;
                
                while (pos < n && p[pos] == '*') {
                    dp[0][pos] = 1; pos++;
                }
            }   
        }
        else if (dp[0][0]) {
            int pos = 1;
            while (pos < n && p[pos] == '*') {
                dp[0][pos] = 1; pos++;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (s[i] == p[j] || p[j] == '?') {
                    if (dp[i - 1][j - 1]) dp[i][j] = 1;
                }
                else if (p[j] == '*') {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        
        if (dp[m - 1][n - 1]) return true;
        
        return false;
    }
};
