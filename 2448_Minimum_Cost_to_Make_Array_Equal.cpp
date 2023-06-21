// https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/
// PreSum + sorting

class Solution {
public:
    #define ll long long
    #define pii pair<int, int>

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        vector<pii> nc;
        for (int i = 0; i < n; i++) nc.push_back({nums[i], cost[i]});
        sort(nc.begin(), nc.end());
        
        vector<ll> ps(n); ps[0] = nc[0].second;
        for (int i = 1; i < n; i++) ps[i] = ps[i - 1] + nc[i].second;

        ll res = 0; int n0 = nc[0].first;
        for (int i = 1; i < n; i++) res += (ll)(nc[i].first - n0) * (ll)nc[i].second;

        ll tres = res;
        for (int i = 1; i < n; i++) {
            int div = nc[i].first - nc[i - 1].first;

            tres += ps[i - 1] * div;
            tres -= (ps[n - 1] - ps[i - 1]) * div;

            res = min(tres, res);
        }

        return res;
    }
};
