// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/submissions/
// stack

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        
        if (n % 3) return false;
        
        
        vector<char> st;
        for (char c : s) {
            if (c == 'c') {
                if (st.size() >= 2) {
                    if (st.back() == 'b') {
                        st.pop_back();
                        
                        if (st.back() == 'a') st.pop_back();
                        else return false;
                    }
                    else return false;
                }
                else return false;
            }
            else st.push_back(c);
        }
        
        return st.empty();
    }
};

// backtracking
class Solution {
public:
    unordered_map<string, int> fre;
    
    bool isStrValid(string s) {
        if (s == "abc" || s.empty()) return true;
        
        if (fre[s]) return false;
        fre[s]++;
        
        int n = s.size();
        
        if (n % 3) return false;
        
        for (int i = 0; i < n - 2; i++) {
            if (s.substr(i, 3) == "abc")
                if (isStrValid(s.substr(0, i) + s.substr(i + 3))) 
                    return true;
        }
        
        return false;
    }
    
    bool isValid(string s) {
        fre.clear();
        return isStrValid(s);
    }
};
