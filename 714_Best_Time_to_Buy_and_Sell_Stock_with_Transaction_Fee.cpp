// DP
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size(), buying = 0, selling = -prices[0];
        for (int i = 1; i < len; i++) {
            buying = max(buying, selling + prices[i] - fee);
            selling = max(selling, buying - prices[i]);
        }
        return buying;
    }
};

// greedy
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size(); if (len < 2) return 0;
        
        for (int i = len - 1; i > 0; i--) prices[i] = prices[i] - prices[i-1];
        //for (int i = 1; i < len; i++) cout << prices[i] << ","; cout << endl;
        
        int sum = 0, res = 0, temPro = 0;
        for (int i = 1; i < len; i++) {
            if (sum == 0) {
                if (prices[i] > 0) {
                    sum += prices[i];
                    temPro = max(temPro, sum - fee);
                }
            }
            else {
                if (prices[i] > 0) {
                    sum += prices[i];
                    temPro = max(temPro, sum - fee);
                }
                else if (sum + prices[i] > 0 && sum + prices[i] > sum - fee) {
                    sum += prices[i];
                    temPro = max(temPro, sum - fee);
                }
                else {
                    res += temPro;
                    sum = 0; temPro = 0;
                }
            }
        }
        cout << res << endl;
        res += max(sum - fee, temPro) ;
        return res;
    }
};
