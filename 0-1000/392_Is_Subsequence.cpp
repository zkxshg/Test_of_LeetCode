// https://leetcode.com/problems/is-subsequence/
// string

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos = 0, n = t.size();
        for (char c : s) {
            while (pos < n && t[pos] != c) pos++;
            if (pos >= n) return false;
            pos++;
        }
        return true;  
    }
};
