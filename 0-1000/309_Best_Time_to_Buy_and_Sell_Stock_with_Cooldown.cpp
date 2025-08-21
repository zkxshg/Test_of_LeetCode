// DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0 || len == 1) return 0;
        
        for (int i = len - 1; i > 0; i--) prices[i] = prices[i] - prices[i-1];
        
        vector<int> pro(len);
        pro[0] = 0; 
        pro[1] = max(0, prices[1]); if (len == 2) return pro[1];
        pro[2] = max(0, prices[2]) + pro[1]; if (len == 3) return pro[2];
        pro[3] = max({pro[2], prices[3] + prices[2] + pro[1], prices[3]}); if (len == 4) return pro[3];
        
        for (int i = 4; i < len; i++) {
            if (prices[i] <= 0) pro[i] = pro[i - 1];
            else if (prices[i - 1] > 0) pro[i] = prices[i] + pro[i - 1];
            else pro[i] = max({prices[i] + pro[i - 3], prices[i] + prices[i - 1] + pro[i - 2], pro[i - 1]});
        }
        
        return pro[len - 1];
    }
};
