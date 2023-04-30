// https://leetcode.com/problems/count-the-number-of-consistent-strings/
// hash map

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> dict;
        for (char c : allowed) dict[c]++;
        int res = 0;
        for (auto& s : words) {
            bool cons = true;
            for (char c : s) {
                if (!dict[c]) {
                    cons = false; break;
                }
            }
            if (cons) res++;
        }
        return res;
        
    }
};
