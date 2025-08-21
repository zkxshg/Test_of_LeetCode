// 3333. Find the Original Typed String II
// Link: https://leetcode.com/problems/find-the-original-typed-string-ii/
// Lang: C++
// Date: 2025-08-21 21:05:30.526 UTC

class Solution {
public:
    #define ll long long
    static const int MOD = 1e9 + 7;

    int possibleStringCount(const string &word, int k) {
        int m = word.size();
        vector<int> groups;
        groups.reserve(m);

        // RLE compression: record run lengths f_i
        for (int i = 0; i < m; ) {
            int j = i;
            while (j < m && word[j] == word[i]) ++j;
            groups.push_back(j - i);
            i = j;
        }

        int n = groups.size();
        // Compute product of f_i
        ll total = 1;
        for (int fi : groups) {
            total = (total * fi) % MOD;
        }

        // If number of runs >= k, choosing one char per run already >= k
        if (n >= k) return (int)total;

        // Otherwise we need sum of (u_i - 1) >= k - n
        int t = k - n;
        int maxSum = t - 1;  // we count "bad" cases with sum <= maxSum

        vector<int> dp(maxSum + 1, 0);
        dp[0] = 1;
        // DP over runs, dimension only up to maxSum (<=2000)
        for (int fi : groups) {
            int cap = fi - 1;
            vector<int> prefix(maxSum + 2, 0);
            for (int j = 0; j <= maxSum; ++j) {
                prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
            }
            for (int j = 0; j <= maxSum; ++j) {
                int l = j - cap;
                if (l < 0) l = 0;
                // number of ways to take sum j using up to cap
                dp[j] = (prefix[j + 1] - prefix[l] + MOD) % MOD;
            }
        }

        // Sum bad cases
        ll bad = 0;
        for (int j = 0; j <= maxSum; ++j) {
            bad = (bad + dp[j]) % MOD;
        }

        // Answer = total - bad
        ll ans = (total - bad + MOD) % MOD;
        return (int)ans;
    }
};
