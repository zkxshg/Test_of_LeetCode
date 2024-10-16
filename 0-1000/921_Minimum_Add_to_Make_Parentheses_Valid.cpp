// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/?envType=daily-question&envId=2024-10-09
// Stack

class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> st;
        for (char c : s) {
            if (!st.empty() && st.back() == '(' && c == ')') st.pop_back();
            else st.push_back(c);
        }
        return st.size();
    }
};
