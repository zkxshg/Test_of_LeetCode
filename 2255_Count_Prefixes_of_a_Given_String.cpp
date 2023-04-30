// https://leetcode.com/problems/count-prefixes-of-a-given-string/
// string

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0, n = s.size();
        for (auto& w : words)
            if (w.size() <= n && s.substr(0, w.size()) == w) res++;
        return res;
    }
};
