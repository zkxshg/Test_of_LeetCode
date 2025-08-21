// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
// string

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        unordered_map<string, int> str;
        str[s] = 1;
        
        string conc = "";
        for (auto& w : words) {
            conc += w; 
            if (str[conc]) return true;
            if (w.size() > s.size()) break;
        }
        
        return false;
    }
};
