// 1957. Delete Characters to Make Fancy String
// Link: https://leetcode.com/problems/delete-characters-to-make-fancy-string/
// Lang: C++
// Date: 2025-08-21 21:00:35.229 UTC

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();

        string res = ""; res += s[0];
        int fre = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                if (fre >= 2) continue;
                else {
                    res += s[i];
                    fre++;
                }
            }
            else {
                res += s[i];
                fre = 1;
            }
        }

        return res;
    }
};
