// https://leetcode.com/problems/counting-words-with-a-given-prefix/
// string

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size(), res = 0;
        for (auto& s : words) 
            if (s.size() >= n && s.substr(0, n) == pref) res++;
        return res;
    }
};
