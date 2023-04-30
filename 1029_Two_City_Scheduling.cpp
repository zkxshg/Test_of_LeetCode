// https://leetcode.com/problems/two-city-scheduling/
// Greedy (largest abs(subs)) + sort
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int peoNum = costs.size();
        if (peoNum == 0) return 0;
        
        int thre = peoNum / 2;
        
        vector<int> subs(peoNum);
        vector<int> subIndex(peoNum);
        for (int i = 0; i < peoNum; i++) {
            subs[i] = abs(costs[i][0] - costs[i][1]);
            subIndex[i] = i;
        }
        QuickSort(subs, subIndex, 0, peoNum - 1);
        
        int city_1 = 0, city_2 = 0, result = 0, pos = peoNum - 1;
        while (city_1 < thre && city_2 < thre) {
            if (costs[subIndex[pos]][0] > costs[subIndex[pos]][1]) {
                result += costs[subIndex[pos]][1];
                city_2++;
            } else {
                result += costs[subIndex[pos]][0];
                city_1++;
            }
            pos--;
        }
        
        if (city_1 < thre) {
            while (pos >= 0) {
                result += costs[subIndex[pos]][0];
                pos--;
            }
        } else {
            while (pos >= 0) {
                result += costs[subIndex[pos]][1];
                pos--;
            }
        }
        
        return result;
    }
    
    void QuickSort(vector<int>& B, vector<int>& BI, int f, int l){
        int x = B[f];
        int i = f + 1;
        int j = l;
        while (i < j){
            while (j >= f + 1 && B[j] >= x) j--;
            while (i <= l && B[i] <= x) i++;
            if (i < j){
                int temp = B[i];
                B[i] = B[j];
                B[j] = temp;
                
                int tempI = BI[i];
                BI[i] = BI[j];
                BI[j] = tempI;
            }
        }
        if (B[f] > B[j]){
            B[f] = B[j];
            B[j] = x;
            
            int tempI = BI[f];
            BI[f] = BI[j];
            BI[j] = tempI;
        }
        if (f < j-1) QuickSort(B, BI, f, j-1);
        if (j+1 < l) QuickSort(B, BI, j+1, l);
    }
};
