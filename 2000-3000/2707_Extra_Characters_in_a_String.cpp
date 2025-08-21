// https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2023-09-02
// DP + hash table

class Solution {
public:
    bool isInDictionary(const unordered_set<string> &dictionary, const string &word) {
        return dictionary.find(word) != dictionary.end();
    }

    int minExtraChar(const string &s, const vector<string> &dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        vector<vector<int>> dp(n, vector<int>(n, n));

        for (int len = 0; len < n; len++) {
            for (int i = 0; i < n - len; i++) {
                int j = i + len;

                string substring = s.substr(i, len + 1);

                if (isInDictionary(dict, substring)) {
                    dp[i][j] = 0;
                }
                else if (i == j){
                    dp[i][j] = 1;
                }
                else {
                    for (int k = i; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }

            }
        }

        return dp[0][n - 1];
    }

};
