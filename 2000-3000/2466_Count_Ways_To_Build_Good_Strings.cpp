// https://leetcode.com/problems/count-ways-to-build-good-strings/description/
// dp

class Solution {
public:
    #define ll long long
    
    int countGoodStrings(int low, int high, int zero, int one) {
        ll ub = 1e9 + 7;

        vector< vector<ll> > dp(high + 1, vector<ll>(2));
        dp[zero][0] = 1; dp[one][1] = 1;

        for (int i = 1; i <= high; i++) {
            if (i > zero) {
                dp[i][0] = (dp[i - zero][0] + dp[i - zero][1]) % ub;
            }
            if (i > one) {
                dp[i][1] = (dp[i - one][0] + dp[i - one][1]) % ub;
            }
        }

        ll res = 0;
        for (int i = low; i <= high; i++) res = (res + dp[i][0] + dp[i][1]) % ub;
        return res;
    }
};
