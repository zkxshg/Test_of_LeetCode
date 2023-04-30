// https://leetcode.com/problems/distinct-subsequences/
// DP

class Solution {
public:
    #define ll long long
    
    void traceBack(vector<vector<pair<int, int> > >& match,  map<pair<int, int>, ll>& path, pair<int, int>& tp, int len) {
        if (path[tp] > 0) return;
        
        if (len <= 1) path[tp] = 1;
        else {
            int i = tp.first, j = tp.second;
            
            for (auto& p : match[len - 1]) {
                if (p.first < i && p.second < j) {
                    if (!path[p]) traceBack(match, path, p, len - 1);
                    path[tp] += path[p]; 
                }
            }     
        }
    }
    
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();

        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        
        vector<vector<pair<int, int> > > match(n + 1);
        map<pair<int, int>, ll> path;
            
        int res = 0;
        
        // DP
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                    pair<int, int> tp = make_pair(i, j);
                    match[dp[i][j]].push_back(tp);
                }   
             }
        }
        
        if (match[n].empty()) return 0;
        
        // Trace Back
        for (auto& mp : match[n]) {
            traceBack(match, path, mp, n);
            res += path[mp];
        }
        
        return res;
    }
};
