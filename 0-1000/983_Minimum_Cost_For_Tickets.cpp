// https://leetcode.com/problems/minimum-cost-for-tickets/description/
// DP

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        int c30 = costs[2], c7 = min(costs[1], c30), c1 = min(costs[0], c7);

        vector<int> dp(n + 1, c1 * 365); 

        dp[0] = 0; dp[1] = c1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + c1;

            for (int j = i - 1; j >= 1; j--) {
                int div = days[i - 1] - days[j - 1];

                if (div < 7) dp[i] = min(dp[i], dp[j - 1] + c7);
                else if (div < 30) dp[i] = min(dp[i], dp[j - 1] + c30);
                else break;
            }
        }
        //for (int i : dp) cout << i << ","; cout << endl;

        return dp.back();  
    }
};
