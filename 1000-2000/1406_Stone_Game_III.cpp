// https://leetcode.com/problems/stone-game-iii/description/
// 1-D DP
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // Resize stoneValue vector and initialize dp
        stoneValue.resize(n + 4);
        vector<int> dp(n + 4, INT_MIN / 2);
        for (int i = n; i < n + 4; ++i) dp[i] = 0;
        
        // Calculate the sum of the stoneValue
        vector<int> pre(n + 5);
        for (int i = 0; i < n + 4; i++) pre[i + 1] = pre[i] + stoneValue[i];
        
        // Bottom-up 1D DP
        for (int i = n - 1; i >= 0; --i) { 
            for (int k = 1; k <= 3; ++k) {
                int stones = pre[i + k] - pre[i];
                dp[i] = max(dp[i], stones - dp[i + k]);
            }
        }
        
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};

// DP + map

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int lb = -50000001;

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + stoneValue[i];

        // Replace 2D vector with a map of pairs of ints
        map<pair<int, int>, int> dp;

        function<int(int, int)> dfs = [&](int l, int r) {
            if (l > r) return 0;
            
            // Access values in the map using make_pair
            auto it = dp.find(make_pair(l, r));
            if (it != dp.end()) return it->second;
            
            int mx = INT_MIN; // Use INT_MIN instead of 'lb'
            for (int i = 1; i <= 3 && l + i - 1 <= r; i++) {
                int stones = pre[l + i] - pre[l];
                mx = max(mx, stones - dfs(l + i, r));
            }
            dp[make_pair(l, r)] = mx;

            return mx;
        };

        int diff = dfs(0, n - 1);

        if (diff == 0) return "Tie";
        return (diff > 0) ? "Alice" : "Bob";
    }
};
