// https://leetcode.com/problems/minimum-cost-to-set-cooking-time/
// Math

class Solution {
public:
    int totalCost(int st, int mc, int pc, string aim) {
        int cost = 0, n = aim.size(); 
        for (int i = 0; i < n; i++) {
            int a = aim[i] - '0';
            
            if (st != a) cost += mc;
            st = a;
            
            cost += pc; 
        } // cout << aim << "=" << cost << endl;
        return cost;
        
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int left = targetSeconds % 60, m = targetSeconds / 60;
        
        string aim1 = (m > 0 ? to_string(m) : "");
        
        if (left >= 10) aim1 += to_string(left);
        else if (m > 0) aim1 += "0" + to_string(left);
        else if (left > 0) aim1 += to_string(left);
        
        int cost = INT_MAX;
        if (m < 100) cost = totalCost(startAt, moveCost, pushCost, aim1);
        
        if (left < 40 && m > 0) {
            left += 60; m--;
            
            string aim2 = (m > 0 ? to_string(m) : "");
        
            if (left >= 10) aim2 += to_string(left);
            else if (m > 0) aim2 += "0" + to_string(left);
            else if (left > 0) aim2 += to_string(left);
            
            cost = min(cost, totalCost(startAt, moveCost, pushCost, aim2));
        }
        
        return cost;
    }
};
