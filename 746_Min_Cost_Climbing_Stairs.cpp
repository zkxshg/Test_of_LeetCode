// DP : total[i] = min(total[i-1], total[i-2]) + cost[i];
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if (len == 0 || len == 1) return 0;
        if (len == 2) {
            if (cost[0] < cost[1]) return cost[0];
            else return cost[1];
        }
        vector<int> total(len);
        total[0] = cost[0];
        total[1] = cost[1];
        for (int i = 2; i < len; i++){
            total[i] = cost[i];
            if (total[i-1] > total[i-2]) total[i] += total[i-2];
            else total[i] += total[i-1];
        }
        int result = 0;  
        if (total[len-1] > total[len-2]) result = total[len-2];
        else result = total[len-1];        
        return result;
    }
};
