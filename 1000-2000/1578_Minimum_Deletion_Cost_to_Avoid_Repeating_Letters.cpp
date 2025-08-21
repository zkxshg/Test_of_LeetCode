// 5509_Minimum_Deletion_Cost_to_Avoid_Repeating_Letters.cpp
// two pointers
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int len = s.size();
        if (len < 2) return 0;
        
        int st = 0, en = 1, total = 0;
        while (st < len) {
            while (en < len && s[en] == s[st]) en++;
            if (en - 1 > st) {
                for (int i = st; i < en; i++) total += cost[i];
                total -= *max_element(cost.begin() + st, cost.begin() + en);
            }
            st = en;
            en++;
        }
        
        return total;
    }
};
