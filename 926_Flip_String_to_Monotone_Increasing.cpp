// https://leetcode.com/problems/flip-string-to-monotone-increasing/description/
// DP

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();

        vector<pair<int, int> > dp(n);

        if (s[0] == '0') {dp[0].first = 0; dp[0].second = 1;}
        else {dp[0].first = 1; dp[0].second = 0;}

        for (int i = 1; i < n; i++) {
            dp[i].first = dp[i - 1].first + (s[i] - '0');
            dp[i].second = min(dp[i - 1].first, dp[i - 1].second) + abs(s[i] - '1');
        }
        
        return min(dp[n - 1].first, dp[n - 1].second);
    }
};
