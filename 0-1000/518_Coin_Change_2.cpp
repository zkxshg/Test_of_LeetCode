// https://leetcode.com/problems/coin-change-2/
// DP

class Solution {
public:
    #define ll long long
    
    int change(int amount, vector<int>& coins) {
        int c = coins.size();
        sort(coins.begin(), coins.end());
        
        vector<ll> am(amount + 1);  am[0] = 1;
        
        for (int co : coins) 
             for (int i = co; i <= amount; i++) 
                 am[i] += am[i - co];
        
        // for (int i : am) cout << i << ","; cout << endl;
        
        return am[amount];
    }
};
