// if (rDict.find(s[i]) == rDict.end()) 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        if (len < 2) return true;
        
        unordered_map<char, char> rDict;
        unordered_map<char, bool> tCheck;
        for (char i = ' '; i <= '~'; i++) tCheck[i] = false;
        
        char rs;
        for (int i = 0; i < len; i++) {
            if (rDict.find(s[i]) == rDict.end()) {
                if (!tCheck[t[i]]) {
                    rDict[s[i]] = t[i];
                    tCheck[t[i]] = true;
                }
                else return false;
            }
            else if (rDict[s[i]] != t[i]) return false; 
        }
        
        return true;
    }
};
