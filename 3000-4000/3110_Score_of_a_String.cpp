// https://leetcode.com/problems/score-of-a-string/?envType=daily-question&envId=2024-06-01
// string

class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        for (int i = 0; i < s.size() - 1; i++) {
           res += abs(s[i] - s[i + 1]);
        }
        return res;
    }
};
