// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// stack
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int len = s.size(); if (len < 2) return s;
        
        vector<pair<char, int> > pv;
        
        for (char ch : s) {
            if (pv.empty()) pv.push_back(make_pair(ch, 1));
            else {
                if (pv.back().first == ch) {
                    pv.back().second++;
                    if (pv.back().second == k) pv.pop_back();
                }
                else pv.push_back(make_pair(ch, 1));
            }
        }
        
        string res = "";
    
        for (auto& p : pv)
            for (int i = 0; i < p.second; i++)
                res += p.first;
    
        return res;
    }
    
    
};
