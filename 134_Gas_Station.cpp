// Greedy
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size(); if (len < 2) {
            if (gas[0] < cost[0]) return -1;
            return 0;
        }
        
        vector<int> trip(len);
        for (int i = 0; i < len; i++) trip[i] = gas[i] - cost[i];
        
        for (int i = 0; i < len; i++) {
            if (trip[i] >= 0) {
                int sum = 0;
                for (int j = 0; j < len; j++) {
                    int pos = (j + i) % len;
                    sum += trip[pos];
                    
                    if (sum < 0) break;
                }
                if (sum >= 0) return i;
            }
        }
        
        return -1;
        
    }
};
