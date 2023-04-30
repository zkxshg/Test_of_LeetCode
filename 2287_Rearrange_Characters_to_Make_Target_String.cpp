// https://leetcode.com/problems/rearrange-characters-to-make-target-string/
// hash table

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<int, int> sfre;
        for (char c : s) sfre[c]++;
        
        unordered_map<int, int> tfre;
        for (char c : target) tfre[c]++;
        
        int res = 100;
        for (auto& p : tfre) res = min(res, sfre[p.first] / p.second);
        
        return res;
    }
};
