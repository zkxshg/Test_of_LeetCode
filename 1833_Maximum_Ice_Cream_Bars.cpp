// https://leetcode.com/problems/maximum-ice-cream-bars/
// sort
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (int c : costs) {
            coins -= c; 
            if (coins < 0) break;
            else res++;
        }
        return res;
    }
};
