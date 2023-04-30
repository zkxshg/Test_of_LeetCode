// https://leetcode.com/problems/palindrome-partitioning-ii/
// DP

class Solution {
public:
    
    bool ifPali(string& s, int st, int en) {
        int l = st, r = en;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        vector<vector<int> > mat(n + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                if (s[i - 1] == rs[j - 1]) mat[i][j] = mat[i - 1][j - 1] + 1;
        
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int ub = 1;
            
            for (int j = 1; j <= n; j++) ub = max(ub, mat[i][j]); 
 
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j <= ub; j++) 
                if (ifPali(s, i - j, i - 1))
                    dp[i] = min(dp[i], dp[i - j] + 1);
        }
        
        // for (int i : dp) cout << i << ","; cout << endl;
        return dp[n] - 1;
        
    }
};
