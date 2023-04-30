// https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
// DP

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= m; i++) 
            for (int j = 1; j <= n; j++) 
                if (s[i - 1] == t[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        
        // for (int i = 0; i <= m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << dp[i][j] << ",";
        //     }
        //     cout << endl;
        // }
            
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (!dp[i][j]) {
                    res++;
                    int b = dp[i][j];
                    if (i > b && j > b && dp[i - 1][j - 1]) {
                        if (i < m && j < n && dp[i + 1][j + 1]) {
                            int suf = 1;
                            while (i + suf <= m && j + suf <= n && dp[i + suf][j + suf]) suf++;
                            
                            if (i + suf > m || j + suf > n) suf--;
                            else if (!dp[i + suf][j + suf]) suf--;
                            
                            res += suf * dp[i - 1][j - 1];
                        }
                    }
                }
                else {
                    int b = dp[i][j];
                    if (i > b && j > b) res++;
                    if (i < m && j < n && !dp[i + 1][j + 1]) res += b;
                }
            }
        }
        
        return res; 
    }
};
