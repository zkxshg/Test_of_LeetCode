// https://leetcode.com/problems/restore-ip-addresses/
// backtracking

class Solution {
public:
    
    vector<string> res;
    
    int s2i(string& s, int st, int en) {
        int res = 0;
        for (int i = st; i <= en; i++) res = res * 10 + (s[i] - '0');
        return res;
    }
    
    void backtrack(string& s, int st, string tm, int pos) {
        int n = s.size();
 
        if (pos == 4) {
            if (n - st > 3) return; // redundant left
            if (n - st > 1 && s[st] == '0') return; // leading zero
            
            if (s2i(s, st, n - 1) <= 255) { // valid IP address
                tm += s.substr(st);
                res.push_back(tm);
            }
            return;
        }
        
        for (int i = 0; i <= 2; i++) {
            if (n - (st + i + 1) > (4 - pos) * 3) continue; // suf redundant
            
            if (n - (st + i + 1) < 4 - pos) break; // suf short
            
            if (i > 0 && s[st] == '0') break; // leading zero
            
            if (s2i(s, st, st + i) <= 255) {
                string nex = tm; //cout << "pre:" << nex << ",";
                nex += s.substr(st, i + 1); nex += '.';  //cout << "after:" << nex << endl;
                backtrack(s, st + i + 1, nex, pos + 1);
                
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        
        int n = s.size(); if (n < 4) return {};
        
        string tm = "";
        backtrack(s, 0, tm, 1);
        
        return res;
    }
};
