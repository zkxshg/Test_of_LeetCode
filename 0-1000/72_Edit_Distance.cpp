// https://leetcode.com/problems/edit-distance/
// DP

class Solution {
public:
    void show_2d(vector<vector<int> >& M) {
        int m = M.size(), n = M[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cout << M[i][j] << ",";
            cout << endl;
        }
        cout << endl;
        
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        
        for (int i = 0; i <= m; i++) dp[i][0] = -i;
        for (int i = 0; i <= n; i++) dp[0][i] = -i;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j - 1] - 1);
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                else dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - 1);
            }
        }
        // show_2d(dp);
        
        return -dp[m][n];
    }
};
