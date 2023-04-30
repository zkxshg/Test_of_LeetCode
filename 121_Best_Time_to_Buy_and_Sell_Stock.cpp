// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// DP: maxProfit(0) = max(maxValue-pos, maxProfit(1))
class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int len = prices.size();
        if (len == 0 || len == 1) return 0;
        int pro = 0;
        int max = 0;
        int pos = len - 2;
        while (pos >= 0){
            if (prices[pos + 1] > max) max = prices[pos + 1];
            int tempro = max - prices[pos]; 
            if (tempro > pro) pro = tempro;
            pos--; 
        }
        return pro;
    }
};
