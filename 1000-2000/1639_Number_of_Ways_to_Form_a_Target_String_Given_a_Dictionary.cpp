// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/
// DP

class Solution {
public:
    #define ll long long
    ll ub = 1e9 + 7;

    ll qmul(ll x, ll y) {
        ll ret = 0;
        while (y) {
            if (y & 1)
                ret = (ret + x) % ub;
            x = x * 2 % ub;
            y >>= 1;
        }
        return ret; // x * y
    }

    int numWays(vector<string>& words, string target) {
        int num = words.size(), m = words[0].size(), n = target.size();

        unordered_map<int, vector<int>> fre;

        for (int i = 0; i < m; i++) {
            fre[i].resize(26);

            for (int j = 0; j < num; j++) fre[i][words[j][i] - 'a']++;
        }

        vector<vector<ll> > dp(n, vector<ll>(m));

        // Boundary Condition
        int t0 = target[0] - 'a';
        dp[0][0] = fre[0][t0];
        for (int i = 1; i < m; i++) dp[0][i] = dp[0][i - 1] + fre[i][t0];
        
        // dp
        for (int i = 1; i < n; i++) {
            int ti = target[i] - 'a';

            for (int j = i; j < m; j++) {
                dp[i][j] = (qmul(dp[i - 1][j - 1], fre[j][ti]) + dp[i][j - 1]) % ub;
            }
        }

        return dp[n - 1][m - 1];
    }
};
