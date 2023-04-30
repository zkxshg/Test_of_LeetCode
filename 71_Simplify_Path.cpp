// https://leetcode.com/problems/simplify-path/
// stack

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        
        int dotNum = 0;
        vector<char> st;
        for (int i = 0; i < n; i++)  { 
            // for (char c : st) cout << c; cout << endl;
            char c = path[i]; 
            
            if (c == '/') {
                if (st.empty()) st.push_back(c); // "/"
                else {
                    if (st.back() == '/') continue; // "//"
                    else if (st.back() == '.') {
                        if (dotNum >= 3) { // /.../
                            st.push_back(c); dotNum = 0; continue;
                        }
                        
                        while (st.back() == '.') st.pop_back();
                        
                        if (st.back() != '/') { // /abc../
                            for (int i = 0; i < dotNum; i++) st.push_back('.');
                            st.push_back(c);
                        }
                        else if (dotNum == 1) { // /ab/./ -> /ab/
                            dotNum = 0; continue; 
                        }
                        else if (dotNum == 2) { // /ab/../ -> /
                            if (st.size() > 1) st.pop_back(); // not root
                            while (st.back() != '/') st.pop_back();
                        }
                        
                        dotNum = 0;
                    }
                    else st.push_back(c);
                }
            }
            else if (c == '.') {
                dotNum++;
                st.push_back(c); 
            }
            else {
                st.push_back(c); dotNum = 0;
            }
            
        }
        
        if (st.size() > 1) {
            if (st.back() == '/') st.pop_back();
            else if (st.back() == '.') {
                if (dotNum == 1) {
                    st.pop_back(); 
                    if (st.size() > 1) st.pop_back();
                }
                else if (dotNum == 2) {
                    while (st.back() != '/') st.pop_back();
                    if (st.size() > 1) st.pop_back();
                    
                    while (st.back() != '/') st.pop_back();
                    if (st.size() > 1) st.pop_back();
                }
            }
        }
        
        string res = ""; for (char c : st) res += c;
        return res;
    }
};
