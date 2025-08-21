// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// stack + math

class Solution {
public:
    int ifInt(string& s) {
        int res = 0, n = s.size(); 
        bool neg = false;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '-') {
                if (i == 0 && n > 1) neg = true;
                else return 233;
            }
            else if (isdigit(s[i])) res = res * 10 + (s[i] - '0');
            else return 233;
        }
        
        if (neg) return -res;
        return res;
    }
    
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        
        vector<int> st;
        for (int i = 0; i < n; i++) {
            int si = ifInt(tokens[i]);
            
            if (si <= 200) st.push_back(si);
            else {
                int bk = st.back(); st.pop_back();
                
                if (tokens[i][0] == '+') st.back() += bk;
                else if (tokens[i][0] == '-') st.back() -= bk;
                else if (tokens[i][0] == '*') st.back() *= bk;
                else if (tokens[i][0] == '/') st.back() /= bk;
            }           
        }
        
        return st[0];
    }
};
