// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
// sorting

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size(), res = 0;
        if (n < 2) return cost[0];
        sort(cost.begin(), cost.end());
        for (int i = n - 1; i >= 0; i -= 3) {
            if (i < 2) {
                if (i < 1) res += cost[0];
                else res += (cost[0] + cost[1]);
            } 
            else res += (cost[i] + cost[i - 1]);
        }
        return res;
    }
};
