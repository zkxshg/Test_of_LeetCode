// https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// greedy

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        unordered_map<int, int> c2i;
        int ind = 0, n = colors.size();
        for (int c : colors) {
            if (!c2i[c]) {
                ind++; c2i[c] = ind;
            }
        }
        
        vector<int> cMax(ind + 1, -1);
        vector<int> cMin(ind + 1, 101);
        
        for (int i = 0; i < n; i++) {
            cMax[c2i[colors[i]]] = max(cMax[c2i[colors[i]]], i);
            cMin[c2i[colors[i]]] = min(cMin[c2i[colors[i]]], i);
        }
        
        int res = 0;
        for (int i = 0; i <= ind; i++)
            if (cMax[i] >= 0) 
                for (int j = 0; j <= ind; j++) 
                    if (cMin[j] <= 100 && i != j)
                        res = max(res, abs(cMax[i] - cMin[j]));
        
        return res;
        
    }
};
