// https://leetcode.com/problems/freedom-trail/
// DP(n^3)

class Solution {
public:
    string R;
    string K;
    unordered_map<char, vector<int> >  dict;
    
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        
        dict.clear();
        for (int i = 0; i < n; i++) dict[ring[i]].push_back(i);
        
        R = ring, K = key;
        
        vector<vector<int> > dp(m, vector<int>(n, INT_MAX));
        for (int pos : dict[key[0]]) dp[0][pos] = min(pos, n - pos);
        //for (int j = 0; j < n; j++) cout << dp[0][j] << ","; cout << endl;
        
        for (int i = 1; i < m; i++) {
            for (int pos : dict[key[i]]) {
                for (int j : dict[key[i - 1]]) {
                    int forw = (pos >= j) ? pos - j : j - pos;
                    int backw = (pos >= j) ? (n + j - pos) : (n + pos - j);
                    
                    dp[i][pos] = min(dp[i][pos], dp[i - 1][j] + min(forw, backw));
                }
            }
            
            //for (int j = 0; j < n; j++) cout << dp[i][j] << ","; cout << endl;
        }
        
        int res = INT_MAX;
        for (int dist : dp[m - 1]) res = min(res, dist);
        return res + m;
    }
};
