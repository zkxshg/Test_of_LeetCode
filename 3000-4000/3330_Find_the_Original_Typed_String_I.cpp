// 3330. Find the Original Typed String I
// Link: https://leetcode.com/problems/find-the-original-typed-string-i/
// Lang: C++
// Date: 2025-08-21 21:05:51.758 UTC

class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1, fre = 0, n = word.size();

        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) fre++;
            else {
                if (fre > 0) res += fre;
                fre = 0;
            }
        } 

        if (fre > 0) res += fre;

        return res;
    }
};
