// https://leetcode.com/problems/water-bottles/?envType=daily-question&envId=2024-07-07
// math

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        int full = numBottles, ept = 0;
        while (full + ept >= numExchange) {
            res += full;
            ept += full;

            full = ept / numExchange;
            ept %= numExchange;
        }
        res += full;
        return res;        
    }
};
