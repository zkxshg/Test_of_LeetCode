// https://leetcode.com/problems/find-good-days-to-rob-the-bank/
// array

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        
        vector<int> res;
        if (n < time * 2 + 1) return res;
        
        vector<int> inc(n); inc[0] = 1;
        vector<int> dec(n); dec[0] = 1;
        for (int i = 1; i < n; i++) {
            if (security[i - 1] == security[i]) {
                inc[i] = inc[i - 1] + 1;
                dec[i] = dec[i - 1] + 1;
            }
            else if (security[i - 1] < security[i]) {
                inc[i] = inc[i - 1] + 1;
                dec[i] = 1;
            }
            else {
                inc[i] = 1;
                dec[i] = dec[i - 1] + 1;
            }
        }
        
        for (int i = time; i < n - time; i++) {
            if (dec[i] > time && inc[i + time] > time) res.push_back(i);
        }
        
        return res;
    }
};
