// https://leetcode.com/problems/split-a-string-in-balanced-strings/
// greedy
class Solution {
public:
    int balancedStringSplit(string s) {
        int sco = 0, res = 0;
        for (char ch : s) {
            if (ch == 'L') sco++;
            else sco--;
            
            if (sco == 0) res++;
        }
        return res;
    }
};
