// array
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size(); if (len < 3) return 1;
        
        vector<int> occs;
        for (int i = 0; i < len; i++) {
            if (seats[i]) occs.push_back(i);
        }
        
        int maxDis = 0;
        maxDis = max(maxDis, occs[0] - 0);
        maxDis = max(maxDis, len - 1 - occs.back());
        
        int lenO = occs.size();
        for (int i = 0; i < lenO - 1; i++) {
            int dist = (occs[i + 1] - occs[i]) / 2;
            if (dist > maxDis) maxDis = dist;
        }
        return maxDis;
    }
};
