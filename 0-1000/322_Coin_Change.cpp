// DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int c = coins.size();
        sort(coins.begin(), coins.end());
        
        vector<int> am(amount + 1, 1e6); am[0] = 0;
        
        for (int i = coins[0]; i <= amount; i++) {
            for (int co : coins)  {
                if (i >= co) am[i] = min(am[i], am[i - co] + 1);
                else break;
            }
        }
        
        if (am[amount] > 1e5) return -1;
        return am[amount];
    }
};
