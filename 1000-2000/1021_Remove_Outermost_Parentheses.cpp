// https://leetcode.com/problems/remove-outermost-parentheses/
// stack
class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> st;
        vector<string> pri;
        
        string tem = "";
        for (char ch : S) {
            if (st.empty()) {
                st.push(ch); tem += ch;
            }
            else {
                if (st.top() == '(' && ch == ')') {
                    st.pop(); tem += ch;
                    
                    if (st.empty()) {
                        pri.push_back(tem); tem = "";
                    }
                }
                else {
                    st.push(ch); tem += ch;
                }
            }
        }
        
        string res = "";
        for (string s : pri) res += s.substr(1, s.size() - 2);
        return res;
    }
};
