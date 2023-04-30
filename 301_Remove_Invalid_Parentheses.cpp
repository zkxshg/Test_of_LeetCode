// https://leetcode.com/problems/remove-invalid-parentheses/
// Backtracking
class Solution {
public:
    int rst, ren, lst, len;
    
    vector<int> rp;
    
    vector<string> res;
    unordered_map<string, int> dict;
    
    void backtrack(string& s, string t, int pos, vector<int> st) {
        int n = s.size();
        
        // if (st.size() >)
        
        if (pos >= n) {
            if (st.empty() && !dict[t]) {
                dict[t]++; 
                
                if (res.empty() || res[0].size() == t.size()) res.push_back(t);
                else if (!res.empty() && res[0].size() < t.size()) {
                    res.clear(); res.push_back(t);
                }
            } 
            return;
        }
        
        if (s[pos] != ')' && s[pos] != '(') {
            t += s[pos]; 
            backtrack(s, t, pos + 1, st);
        }
        else if (s[pos] == '(') {
            if (lst >= 0 && pos > ren) {
                backtrack(s, t, pos + 1, st); // delete
                
                if (rp[pos] > st.size()) {
                    t += s[pos]; st.push_back(1);
                    backtrack(s, t, pos + 1, st); // not delete 
                }
            }
            else {
                t += s[pos]; st.push_back(1);
                backtrack(s, t, pos + 1, st); // not delete
            }
        }
        else if (s[pos] == ')') {
            if (rst >= 0 && pos <= ren) {
                backtrack(s, t, pos + 1, st); // delete
                
                if (!st.empty()) {
                    st.pop_back();  t += s[pos];
                    backtrack(s, t, pos + 1, st); // not delete
                }
            }
            else if (!st.empty()) {
                st.pop_back();  t += s[pos];
                backtrack(s, t, pos + 1, st); // not delete
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        
        vector<char> st; vector<int> stPos;
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            
            if (c != '(' && c != ')') continue;
            
            if (!st.empty() && st.back() == '(' && c == ')') {
                st.pop_back(); stPos.pop_back();
            }
            else {
                st.push_back(c); stPos.push_back(i);
            }
        }
        
        int left = st.size();
        if (!left) return {s};
        
        //for (char c : st) cout << c << ","; cout << endl;
        
        rst = ren = lst = len = -1; 
        res.clear(); dict.clear();
        
        int pos = 0; 
        
        if (st[0] == ')') rst = stPos[0];
        else lst = stPos[0];
        
        while (pos < left && st[pos] == ')') {
            ren = max(ren, stPos[pos]); pos++;
        }
        
        if (pos < left && st[pos] == '(') lst = stPos[pos];
        while (pos < left && st[pos] == '(') {
            len = max(len, stPos[pos]); pos++;
        }
        
        // cout << rst << ":" << ren << "," << lst << ":" << len << endl;
        
        rp.clear(); rp.resize(n, 0);
        if (s[n - 1] == ')') rp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == ')') rp[i] = rp[i + 1] + 1;
            else rp[i] = rp[i + 1];
        }
        // for (int i : rp) cout << i << ","; cout << endl;
        
        backtrack(s, "", 0, {});
        
        return res;
    }
};

// bitmask
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        
        vector<int> st;
        for (char c : s) {
            if (c != '(' && c != ')') continue;
            if (!st.empty() && st.back() == '(' && c == ')') st.pop_back();
            else st.push_back(c);
        }
        
        int left = st.size();
        if (!left) return {s};
        
        vector<string> res;
        unordered_map<string, int> dict;
        
        vector<int> pArr;
        for (int i = 0; i < n; i++) if (s[i] == '(' || s[i] == ')') pArr.push_back(i);

        int m = pArr.size();
        int maskLen = 1 << m;
        for (int i = 0; i < maskLen; i++) {
            unordered_map<int, int> ppos;
            
            bitset<32> bits(i);
            
            int pnum = 0; 
            
            for (int j = 0; j < m; j++) {
                if (!bits[j]) pnum++;
                else ppos[pArr[j]]++;    
            }
            
            if (pnum != left) continue;
            
            vector<int> tst;
            
            for (int j = 0; j < m; j++) {
                if (bits[j]) {
                    char c = s[pArr[j]];
                    
                    if (c != '(' && c != ')') continue;
                    if (!tst.empty() && tst.back() == '(' && c == ')') tst.pop_back();
                    else tst.push_back(c);
                }
            }
            
            if (tst.empty()) {
                string str = "";
                for (int j = 0; j < n; j++) {
                    if (s[j] != '(' && s[j] != ')') str += s[j];
                    else if (ppos[j]) str += s[j];
                }
                
                if (!dict[str]) {
                    res.push_back(str); dict[str]++;
                }
            }
        }
        
        return res;
    }
};
