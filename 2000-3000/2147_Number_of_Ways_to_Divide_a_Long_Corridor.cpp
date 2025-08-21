// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
// DP

class Solution {
public:
    #define cor corridor
    #define ll long long
    ll ub = 1e9 + 7;

    int numberOfWays(string corridor) {
        int n = cor.size();
        
        vector<int> dp(n);

        ll res = 1;
        int snum = 0, pnum = 0;
        for (int i = 0; i < n; i++) {
            if (cor[i] == 'S') {
                snum++;
                if (snum % 2 == 1 && snum > 2) {
                    if (pnum > 0) res = (res * (pnum + 1)) % ub;
                    pnum = 0;
                }
            }
            else {
                if (snum % 2 == 0 && snum > 0) pnum++;
            }
        }

        if (snum % 2 || snum == 0) return 0;
        return res;
    }
};
