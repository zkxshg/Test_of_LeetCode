// https://leetcode.com/problems/lemonade-change/
// Greedy

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cash(3);
        
        for (int order : bills) {
            if (order == 5) cash[1]++;
            else if (order == 10) {
                if (cash[1] > 0) {
                    cash[1]--; cash[2]++;
                }
                else return false;
            }
            else {
                if (cash[2] > 0 && cash[1] > 0) {
                    cash[2]--; cash[1]--;
                }
                else if (cash[1] >= 3) cash[1] -= 3;
                else return false;
            }
        }
        
        return true;
    }
};
