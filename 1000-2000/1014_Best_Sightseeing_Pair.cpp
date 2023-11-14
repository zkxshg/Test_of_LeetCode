// https://leetcode.com/problems/best-sightseeing-pair/
// DP

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, better = values[0], n = values.size();
        
        for (int i = 1; i < n; i++) {
            better--;
            res = max(values[i] + better, res);
            better = max(better, values[i]);
        }
        
        return res;
    }
};
