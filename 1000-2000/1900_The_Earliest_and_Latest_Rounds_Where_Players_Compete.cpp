// 1900. The Earliest and Latest Rounds Where Players Compete
// Link: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/
// Lang: C++
// Date: 2025-08-21 21:02:58.328 UTC

class Solution {
public:
    int dpMin[29][29][29], dpMax[29][29][29];
public:
    Solution() {
        memset(dpMin, -1, sizeof(dpMin));
        memset(dpMax, -1, sizeof(dpMax));
    }

    // Returns {earliest, latest} round for state (n, a, b)
    pair<int,int> dfs(int n, int a, int b) {
        if (a > b) swap(a, b);
        // memoized?
        if (dpMin[n][a][b] != -1) 
            return {dpMin[n][a][b], dpMax[n][a][b]};

        // They meet this round
        if (a + b == n + 1) {
            dpMin[n][a][b] = dpMax[n][a][b] = 1;
            return {1, 1};
        }

        // Collect the "other" matches not involving a or b
        vector<pair<int,int>> other;
        for (int i = 1; i <= n/2; ++i) {
            int j = n + 1 - i;
            // skip any pair touching a or b
            if (i==a||i==b||j==a||j==b) continue;
            other.emplace_back(i,j);
        }

        int m = other.size();
        int bestMin = INT_MAX, bestMax = 0;

        // Enumerate all 2^m ways the other matches can go
        for (int mask = 0; mask < (1<<m); ++mask) {
            vector<int> winners;
            winners.reserve(m+3);

            // a and b always win their own matches (since they're best)
            winners.push_back(a);
            winners.push_back(b);

            // middle player auto-advances if n is odd
            if (n & 1) {
                int mid = (n+1)/2;
                if (mid!=a && mid!=b)
                    winners.push_back(mid);
            }

            // winners from the other matches
            for (int k = 0; k < m; ++k) {
                auto [x,y] = other[k];
                if (mask & (1<<k)) winners.push_back(y);
                else                winners.push_back(x);
            }

            sort(winners.begin(), winners.end());
            int nn = winners.size();

            // find new positions of a and b
            int na=0, nb=0;
            for (int i = 0; i < nn; ++i) {
                if (winners[i]==a) na = i+1;
                if (winners[i]==b) nb = i+1;
            }

            auto [subMin, subMax] = dfs(nn, na, nb);
            bestMin = min(bestMin, subMin+1);
            bestMax = max(bestMax, subMax+1);
        }

        dpMin[n][a][b] = bestMin;
        dpMax[n][a][b] = bestMax;
        return {bestMin, bestMax};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        auto [mn, mx] = dfs(n, firstPlayer, secondPlayer);
        return {mn, mx};
    }
};
