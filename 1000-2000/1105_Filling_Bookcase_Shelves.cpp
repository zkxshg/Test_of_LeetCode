// https://leetcode.com/problems/filling-bookcase-shelves/?envType=daily-question&envId=2024-07-31
// DP

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();

        vector<int> dp(n + 1, INT_MAX); 
        dp[0] = 0; dp[1] = books[0][1];

        for (int i = 2; i <= n; i++) {
            int totalThick = 0;
            int shelfHeight = books[i - 1][1];
            for (int j = i; j > 0; j--) {
                totalThick += books[j - 1][0];
                shelfHeight = max(shelfHeight, books[j - 1][1]);

                if (totalThick <= shelfWidth) {
                    dp[i] = min(dp[i], dp[j - 1] + shelfHeight);
                }
                else break;
            }
        }

        return dp[n];
    }
};
