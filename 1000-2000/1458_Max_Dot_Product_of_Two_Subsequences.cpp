// https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2023-10-08
// DP

class Solution {
public:
    void print_2d(vector<vector<int> >& dp) {
        for (const auto& row : dp) {
            for (const int& element : row) {
                cout << element << " ";
            }
            cout << endl;
        }
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<vector<int> > dp(m, vector<int>(n));
        dp[0][0] = nums1[0] * nums2[0];

        for (int i = 1; i < n; i++) dp[0][i] = max(dp[0][i - 1], nums1[0] * nums2[i]);
        for (int i = 1; i < m; i++) dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], nums1[i] * nums2[j]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + max(0, nums1[i] * nums2[j]));
            }
        }

        //print_2d(dp);

        return dp[m - 1][n - 1];
    }
};
