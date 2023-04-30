// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// stack
// string -> vector<"()"> + map -> stack + pos_stack -> new_string
class Solution {
public:
    string minRemoveToMakeValid(string s) { 
        int m = s.size();
        
        vector<char> c;
        unordered_map<int, int> c2s;
        
        int cou = 0;
        for (int i = 0; i < m; i++) {
            if (s[i] == '(' || s[i] == ')') {
                c.push_back(s[i]); 
                c2s[cou] = i;
                cou++;
            }
        }

        stack<char> st;
        vector<int> st_pos;
        int n = cou;
        
        for (int i = 0; i < n; i++) {
            if (c[i] == '(') {
                st.push(c[i]); st_pos.push_back(i);
            }
            else {
                if (st.empty() || st.top() == ')') {
                    st.push(c[i]); st_pos.push_back(i);
                }
                else if (st.top() == '(') {
                    st.pop(); st_pos.pop_back();
                }
            }
        }
        
        int r = st_pos.size();
        for (int i = 0; i < r; i++) st_pos[i] = c2s[st_pos[i]];

        reverse(st_pos.begin(), st_pos.end());

        string res = "";
        for (int i = 0; i < m; i++) {
            if (!st_pos.empty() && i == st_pos.back()) st_pos.pop_back();
            else res += s[i];
        }
        
        return res;
    }
};
