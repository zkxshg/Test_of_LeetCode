https://leetcode.com/problems/longest-ideal-subsequence/?envType=daily-question&envId=2024-04-25
// DP

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> pos(26, -1);

        int n = s.size();
        vector<int> dp(n, 1); pos[s[0] - 'a'] = 0;

        int res = 1;
        for (int i = 1; i < n; i++) {
            int cha = s[i] - 'a';

            for (int j = 0; j <= k; j++) {
                if (cha - j < 0) break;
                if (pos[cha - j] >= 0) dp[i] = max(dp[i], dp[pos[cha - j]] + 1);
            }

            for (int j = 0; j <= k; j++) {
                if (cha + j >= 26) break;
                if (pos[cha + j] >= 0) dp[i] = max(dp[i], dp[pos[cha + j]] + 1);
            }

            res = max(res, dp[i]);
            pos[cha] = i;
        }

        return res;
    }
};
