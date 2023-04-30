// https://leetcode.com/problems/remove-palindromic-subsequences/
// sub - sequence
class Solution {
public:
    int removePalindromeSub(string s) {
        int len = s.size(); if (len < 1) return 0;
        string s1 = s; reverse(s1.begin(), s1.end());
        if (s1 == s) return 1;
        return 2;
    }
};
