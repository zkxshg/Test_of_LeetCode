// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/?envType=daily-question&envId=2024-06-03
// Greedy + Two points

class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size(), n = t.size();
        int tp = 0;
        for (int i = 0; i < m; i++) {
            if (tp < n && s[i] == t[tp]) tp++;
        }
        return n - tp;
    }
};
