// https://leetcode.com/problems/stone-game-iii/description/
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
