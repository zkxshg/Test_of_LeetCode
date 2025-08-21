// https://leetcode.com/problems/number-of-lines-to-write-string/
// string

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int res = 0, left = 100;
        for (char c : s) {
            if (left >= widths[c - 'a']) left -= widths[c - 'a'];
            else {
                res++; left = 100 - widths[c - 'a'];
            }
        }
        return {res + 1, 100 - left};
    }
};
