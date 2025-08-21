// https://leetcode.com/problems/heaters/
// binary search + two points

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int m = houses.size(), n = heaters.size();
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        vector<int> rds(m, 1000000001);
        
        // i == 0
        int h0 = heaters[0], lb0 = lower_bound(houses.begin(), houses.end(), h0) - houses.begin();
        int pre = lb0 - 1;
        while (pre >= 0) {rds[pre] = h0 - houses[pre]; pre--;}
        
        // i == n - 1
        int hn = heaters[n - 1], lbn = lower_bound(houses.begin(), houses.end(), hn) - houses.begin();
        int nex = lbn;
        while (nex < m) {rds[nex] = houses[nex] - hn; nex++;}
        
        int pos = lb0;
        for (int i = 0; i < n - 1; i++) {
            int h1 = heaters[i], h2 = heaters[i + 1];
            
            int lb =  lower_bound(houses.begin() + pos, houses.end(), h2) - houses.begin();
            
            for (int j = pos; j < lb; j++) rds[j] = min(houses[j] - h1, h2 - houses[j]);

            pos = lb;
        }
        
        //for (int i : rds) cout << i << ","; cout << endl;
        
        return *max_element(rds.begin(), rds.end());
    }
};
