// https://leetcode.com/problems/strange-printer/
// DP (n^3)

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        
        string ns; ns += s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] == ns.back()) continue;
            else ns += s[i];
        }
        
        s = ns; n = s.size();
        
        vector<vector<int> > dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        
        for (int len = 1; len < n; len++) {
            for (int st = 0; st < n - len; st++) {
                int en = st + len;
                
                dp[st][en] = dp[st][st] + dp[st + 1][en];
                
                for (int k = st; k < en; k++) {
                    int comb = dp[st][k] + dp[k + 1][en];
                    if (s[k] == s[en]) comb--;
                    
                    dp[st][en] = min(dp[st][en],  comb);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

// DP - 2
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        
        string ns; ns += s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] == ns.back()) continue;
            else ns += s[i];
        }
        
        cout << ns << endl;
        return 233;
        
        vector<int> dp(n, 0);
        vector<int> suc(n, 0);
        for (int i = 1; i < n; i++) {
            int maxPre = 0;
            
            for (int j = i - 1; j >= 0; j--) {
                suc[i] = max(suc[i], maxPre + suc[j]);
                
                if (s[i] == s[j] || dp[j]) dp[j] = max(dp[j], maxPre + 1);
                
                maxPre = max(maxPre, dp[j]);  
            }
            suc[i] = max(suc[i], maxPre);
        }
        
        for (int i : dp) cout << i << ","; cout << endl;
        for (int i : suc) cout << i << ","; cout << endl;
        return n - suc[n - 1];
    }
};

// DP - 3
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        
        vector<int> dp(n); dp[0] = 1;
        vector<int> pre(26, -1); pre[s[0] - 'a'] = 0;
        
        int rec = -1;
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + 1;
            
            if (pre[s[i] - 'a'] >= 0) {
                if (rec < 0) {
                    dp[i] = dp[i - 1]; rec = pre[s[i] - 'a'];
                }
                else if (s[i] == s[i - 1]) dp[i] = dp[i - 1];
                else {
                    bool suc = false;
                    for (int j = pre[s[i] - 'a']; j >= 0; j--) {
                        if (s[j] == s[i] && j <= rec) {
                            dp[i] = dp[i - 1]; rec = j; suc = true;
                            break;
                        }
                    }
                    
                    if (!suc) rec = pre[s[i] - 'a'];
                }
            }
            
            pre[s[i] - 'a'] = i;
        }
        
        // for (int i : dp) cout << i << ","; cout << endl;
        return dp[n - 1];
    }
};
