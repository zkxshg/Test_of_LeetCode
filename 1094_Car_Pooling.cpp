// https://leetcode.com/problems/car-pooling/
// array + greedy
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int len = trips.size(); if (len < 1) return true;
        
        int tripLen = 0;
        for (vector<int> trip : trips) {
            if (trip[2] > tripLen) tripLen = trip[2];
        }
        
        vector<int> caps(tripLen + 1, capacity);
        for (vector<int> trip : trips) {
            for (int i = trip[1]; i < trip[2]; i++) {
                caps[i] -= trip[0];
                if (caps[i] < 0) return false;
            }
        }
        
        return true;
    }
};
