// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Calculate difference array -> sum all positive nums
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0 || len == 1) return 0;
        for (int i = len - 1; i > 0; i--) prices[i] = prices[i] - prices[i-1];
        int sum = 0;
        for (int i = 1; i < len; i++) {
            if (prices[i] > 0) sum += prices[i]; 
        }
        return sum; 
    }
};
