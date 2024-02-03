// https://leetcode.com/problems/partition-array-for-maximum-sum/
// DP

class Solution {
public:
    #define ll long long

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<ll> dp(n);

        int maxPre = 0;
        for (int i = 0; i < k; i++) {
            maxPre = max(maxPre, arr[i]);
            dp[i] = maxPre * (i + 1);
        }

        for (int i = k; i < n; i++) {
            int maxI = 0;

            for (int j = 0; j < k; j++) {
                maxI = max(maxI, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j - 1] + (j + 1) * maxI);
            }
        }

        return dp.back();
    }
};
