// https://leetcode.com/problems/get-equal-substrings-within-budget/?envType=daily-question&envId=2024-05-28
// sliding window

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        vector<int> cost;
        for (int i = 0; i < n; i++) cost.push_back(abs(s[i] - t[i]));

        int st = 0, en = 0, tmp = cost[0], res = 0;

        while (en < n) {
            if (tmp <= maxCost) {
                res = max(res, en - st + 1);

                en++; 
                if (en < n) tmp += cost[en]; 
            }
            else {
                if (st < en) {
                    tmp -= cost[st];
                    st++;
                }
                else {
                    en++; st = en;
                    if (en < n) {
                        tmp = cost[en];
                    }
                }

            }
        }

        return res;
    }
};
