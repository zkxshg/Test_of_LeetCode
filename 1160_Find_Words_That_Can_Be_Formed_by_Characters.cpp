// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
// hash table

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cf(26);
        for (auto& c : chars) cf[c - 'a']++;
        
        int res = 0;
        for (auto& w : words) {
            vector<int> bd = cf;
            bool form = true;
            
            for (auto& c : w) {
                bd[c - 'a']--;
                
                if (bd[c - 'a'] < 0) {
                    form = false; break;
                }
            }
            
            if (form) res += w.size();
        }
        
        return res;
    }
};
