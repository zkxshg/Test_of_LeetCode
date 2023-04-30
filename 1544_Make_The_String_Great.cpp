// https://leetcode.com/problems/make-the-string-great/
// stack

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        
        vector<char> st;
        for (char c : s) {
            if (!st.empty() && abs(st.back() - c) == 32) st.pop_back();
            else st.push_back(c);
        }
        
        string res = "";
        for (char c : st) res += c;
        return res;
    }
};
