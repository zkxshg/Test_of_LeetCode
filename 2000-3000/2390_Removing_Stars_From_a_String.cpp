// https://leetcode.com/problems/removing-stars-from-a-string/description/
// stack

class Solution {
public:
    string removeStars(string s) {
        string st = "";
        for (char c : s) {
            if (c == '*') st.pop_back();
            else st += c;
        }
        return st;
    }
};
