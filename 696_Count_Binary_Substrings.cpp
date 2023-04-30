// https://leetcode.com/problems/count-binary-substrings/
// greedy
class Solution {
public:
    int countBinarySubstrings(string s) {
        int len = s.size(); if (len < 2) return 0;
        
        int cs0 = 0, cs1 = 0;
        
        if (s[0] == '0') cs0++;
        else cs1++;
        
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '0') cs0++;
                else cs0 = 1;
                
                if (cs0 <= cs1) res++;
            }
            else {
                if (s[i - 1] == '1') cs1++;
                else cs1 = 1;
                
                if (cs1 <= cs0) res++;
            }
        }
        
        return res;
        
    }
};
