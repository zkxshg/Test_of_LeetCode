// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// hash map
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int len = time.size(); if (len < 2) return 0;
        
        for (int i = 0; i < len; i++) time[i] = time[i] % 60;
        
        unordered_map<int, int> numDict;
        for (int i : time) numDict[i]++;
        
        int res = 0;
        for (int i : time) {
            numDict[i]--;
            
            if (i == 0) res += numDict[0];
            else if (numDict[60 - i]) res += numDict[60 - i];
        }
        return res;
    }
};
