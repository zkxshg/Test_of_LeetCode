// 3363. Find the Maximum Number of Fruits Collected
// Link: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/
// Lang: C++
// Date: 2025-08-21 20:51:28.660 UTC

class Solution {
public:
    #define ll long long
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size(), m = (n + 1) / 2;

        int diagSum = 0;
        for (int i = 0; i < n; i++) diagSum += fruits[i][i];

        vector<vector<ll> > dp_1(n, vector<ll>(m, INT_MIN / 2));
        dp_1[0][0] = fruits[0][n - 1];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int tem = 0;
                if (i != n - 1 - j) tem = fruits[i][n - 1 - j];

                dp_1[i][j] = dp_1[i - 1][j];
                if (j > 0) dp_1[i][j] = max(dp_1[i][j], dp_1[i - 1][j - 1]);
                if (j < m - 1) dp_1[i][j] = max(dp_1[i][j], dp_1[i - 1][j + 1]);

                dp_1[i][j] += tem;
            }

            //for (int j = 0; j < m; j++) cout << dp_1[i][j] << ","; cout  << endl;
        } //cout << endl;

        vector<vector<ll> > dp_2(n, vector<ll>(m, INT_MIN / 2));
        dp_2[0][0] = fruits[n - 1][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int tem = 0;
                if (i != n - 1 - j) tem = fruits[n - 1 - j][i];
                
                // cout << i << ":" << j << endl;

                dp_2[i][j] = dp_2[i - 1][j];
                if (j > 0) dp_2[i][j] = max(dp_2[i][j], dp_2[i - 1][j - 1]);
                if (j < m - 1) dp_2[i][j] = max(dp_2[i][j], dp_2[i - 1][j + 1]);

                dp_2[i][j] += tem;
            }

            //for (int j = 0; j < m; j++) cout << dp_2[i][j] << ","; cout  << endl;
        }

        return diagSum + dp_1[n - 1][0] + dp_2[n - 1][0];
    }
};
