// https://leetcode.com/problems/knight-dialer/
// DP

class Solution {
public:
    #define ll long long
    ll ub = 1e9 + 7;

    int knightDialer(int n) {
        vector<vector<ll> > dp(n, vector<ll>(10));
        for (int i = 0; i < 10; i++) dp[0][i] = 1;

        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][4] + dp[i - 1][6]) % ub;
            dp[i][1] = (dp[i - 1][6] + dp[i - 1][8]) % ub;
            dp[i][2] = (dp[i - 1][7] + dp[i - 1][9]) % ub;
            dp[i][3] = (dp[i - 1][4] + dp[i - 1][8]) % ub;
            dp[i][4] = (dp[i - 1][3] + dp[i - 1][9] + dp[i - 1][0]) % ub;
            dp[i][6] = (dp[i - 1][1] + dp[i - 1][7] + dp[i - 1][0]) % ub;
            dp[i][7] = (dp[i - 1][2] + dp[i - 1][6]) % ub;
            dp[i][8] = (dp[i - 1][1] + dp[i - 1][3]) % ub;
            dp[i][9] = (dp[i - 1][2] + dp[i - 1][4]) % ub;
        }

        ll res = 0;
        for (int i = 0; i < 10; i++) res = (res + dp[n - 1][i]) % ub;
        return res;
    }

};
