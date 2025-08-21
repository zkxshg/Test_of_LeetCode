// https://leetcode.com/problems/find-and-replace-pattern/
// map
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.size();
        vector<string> res;
        for (string s : words) {
            bool same = true;
            unordered_map<char, char> P; unordered_map<char, char> invP;
            
            for (int i = 0; i < n; i++) {
                if (P.find(s[i]) == P.end()) {
                    if (invP.find(pattern[i]) != invP.end()) {
                        same = false; break;
                    }
                    else {
                        P[s[i]] = pattern[i]; invP[pattern[i]] = s[i];
                    }
                    
                }
                else if (P[s[i]] != pattern[i]) {
                    same = false; break;
                }

            }
            
            if (same) res.push_back(s);
        }
        
        return res;
        
    }
};
