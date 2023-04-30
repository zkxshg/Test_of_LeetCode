// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// DP + Kadane algos
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0 || len == 1) return 0;
        
        vector<int> profit(len - 1);
        for (int i = len - 1; i > 0; i--) profit[i - 1] = prices[i] - prices[i-1];
        
        vector<int> res = maxProf(profit);
        
        int result2 = 0;
        if (res[2] - res[1] < len - 1) {
            int secMaxP = 0;
            vector<int> secpro(profit.begin(), profit.begin() + res[1]);
            if (secpro.size() > 0) secMaxP =  maxProf(secpro)[0];
            
            int rdMaxP = 0;
            vector<int> rdpro(profit.begin() + res[2] + 1, profit.end());
            if (rdpro.size() > 0) rdMaxP =  maxProf(rdpro)[0];
            
            secMaxP = max(secMaxP, rdMaxP);
            
            if (secMaxP > 0 && res[0] + secMaxP > 0) result2 = res[0] + secMaxP;
        }
        
        vector<int> minProf(profit.begin() + res[1], profit.begin() + res[2] + 1);
        for (int i = 0; i < minProf.size(); i++) minProf[i] = -minProf[i];
        int minPro = -maxProf(minProf)[0];
        
        if (minPro < 0) res[0] = res[0] - minPro;
        
        res[0] = max(result2, res[0]);
        
        return res[0];
    }
    
    vector<int> maxProf(vector<int>& profit) {
        int len = profit.size();
        int start = 0, end = 0, tempPro = profit[0];
        int maxStart = 0, maxEnd = 0, maxPro = profit[0];
        
        for (int i = 1; i < len; i++) {
            if (tempPro + profit[i] > profit[i]) {
                tempPro = tempPro + profit[i];
                end = i;
                if (tempPro > maxPro) {
                    maxStart = start;
                    maxEnd = end;
                    maxPro = tempPro;
                }
            } else {
                tempPro = profit[i];
                start = i;
                end = i;
                if (tempPro > maxPro) {
                    maxStart = start;
                    maxEnd = end;
                    maxPro = tempPro;
                }
            }
        }
        
        vector<int> result;
        result.push_back(maxPro); result.push_back(maxStart); result.push_back(maxEnd);
        return result;
    }
};
