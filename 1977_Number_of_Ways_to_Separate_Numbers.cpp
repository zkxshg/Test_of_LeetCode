// https://leetcode.com/problems/number-of-ways-to-separate-numbers/
// DP + Prefix Array

class Solution {
public:
    #define ll long long
    ll ub = 1e9 + 7;
    string str;
    
    vector<vector<int>> diffs;
    
    bool comp(string a, string b) { //cout << a << ":" << b << endl;
        if (a.size() > b.size()) return true;
        else if (a.size() < b.size()) return false;
        else {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] > b[i]) return true;
                else if (a[i] < b[i]) return false;
            }
        }
        return true;
    }
    
    bool comp(int ai, int aj, int bi, int bj) { //cout << a << ":" << b << endl;
        if (aj - ai > bj - bi) return true;
        else if (aj - ai  < bj - bi) return false;
        else {
            if (str.substr(ai, aj - ai + 1) == str.substr(bi, bj - bi + 1)) return true;
            
            for (int i = 0; i <= aj - ai; i++) {
                if (str[ai + i] > str[bi + i]) return true;
                else if (str[ai + i] < str[bi + i]) return false;
            }
        }
        return true;
    }
    
    vector<vector<string> > slice(string& num) {
        int n = num.size();
        
        vector<vector<string> > sle(n, vector<string>(n));
        
        for (int i = 0; i < n; i++) sle[i][i] = num[i];
        
        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) sle[i][j] = sle[i][j - 1] + num[j];
        
        return sle;
    }
    
    int diff(string& s, int x, int y) {
        int n = s.size();
        
        if (y >= n) return n;
        
        if (diffs[x][y] >= 0) return diffs[x][y];
        
        if (s[x] != s[y]) return y;
        
        return diff(s, x + 1, y + 1);
    }
    
    int numberOfCombinations(string num) {
        if (num[0] == '0') return 0;
        
        int n = num.size(); str = num;
        
        diffs.resize(n, vector<int>(n, -1));

        for (int i = n - 1; i >= 0; i--) 
            for (int j = i; j < n; j++) 
                diffs[i][j] = diff(num, i, j);

        vector<vector<ll> > dp(n + 1, vector<ll>(n + 1));
        
        for (int i = 1; i <= n; i++) dp[i][i] = 1;
        
        for (int i = 1; i <= n; i++) {
            
            for (int j = 1; j < i; j++) {
                dp[i][j] = dp[i][j - 1];
                
                if (num[i - j] == '0') continue;
                
                if (i - j < j) dp[i][j] = (dp[i][j] + dp[i - j][i - j]) % ub;
                else {
                    int dij = diffs[i - 2 * j][i - j];
                    
                    int dist = dij - (i - j);
                    
                    if (dij >= i || num[i - 2 * j + dist] <= num[i - j + dist])
                        dp[i][j] = (dp[i][j] + dp[i - j][j]) % ub;
                    else dp[i][j] = (dp[i][j] + dp[i - j][j - 1]) % ub;
                } 
                
                //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << ",";
            } 
            
            dp[i][i] = (dp[i][i] + dp[i][i - 1]) % ub;
            //cout << "dp[" << i << "][" << i<< "] = " << dp[i][i] << ","; cout << endl;   
        }
        
        return dp[n][n];
    }
};
