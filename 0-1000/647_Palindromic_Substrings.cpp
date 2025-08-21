// https://leetcode.com/problems/palindromic-substrings/
// DP
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size(); if (len < 2) return len;
        
        int res = 0;
        // odd
        vector<pair<int, int> > oddP;
        for (int i = 0; i < len; i++) oddP.push_back(make_pair(i, i));
        res += len;
        
        while (!oddP.empty()) {
            vector<pair<int, int>> tem;
            
            for (auto& p : oddP) {
                if (p.first > 0 && p.second < len - 1) {
                    if (s[p.first - 1] == s[p.second + 1]) {
                        res++;
                        tem.push_back(make_pair(p.first - 1, p.second + 1));
                    }
                }
            }
            
            oddP = tem;
        }
        
        //even
        vector<pair<int, int> > evenP;
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1]) {
                evenP.push_back(make_pair(i, i + 1)); res++;
            }
        }
        
        while (!evenP.empty()) {
            vector<pair<int, int>> tem;
            
            for (auto& p : evenP) {
                if (p.first > 0 && p.second < len - 1) {
                    if (s[p.first - 1] == s[p.second + 1]) {
                        res++;
                        tem.push_back(make_pair(p.first - 1, p.second + 1));
                    }
                }
            }
            
            evenP = tem;
        }
        
        return res;
        
    }
};
