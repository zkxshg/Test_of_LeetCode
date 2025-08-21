// https://leetcode.com/problems/zigzag-conversion/description/
// string

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> zz(numRows);

        bool pos = true; int r = 0;

        for (char c : s) {
            zz[r] += c;

            if (pos) {
                r++;
                if (r >= numRows) {
                    pos = false; r -= 2;
                }
            }
            else {
                r--;
                if (r < 0) {
                    pos = true; r += 2;
                }
            }
        }

        string res = "";
        for (int i = 0; i < numRows; i++) res += zz[i];

        return res;
    }
};
