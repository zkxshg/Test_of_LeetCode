// https://leetcode.com/problems/repeated-string-match/
// string matching

class Solution {
public:
    int repNum(string& a, string& b, int pos) {
        int m = a.size(), n = b.size();
        if (pos >= n) return 0;
        
        string suf_b = b.substr(pos);
        
        // match a-pre with b-suf
        int len = suf_b.size();
        for (int i = 0; i < len; i++) 
            if (suf_b[i] != a[i % m]) 
                return 10001;
        // cout << suf_b << " = " << len << "/" << m << endl;
        return len / m + 1;
    }
    
    int repeatedStringMatch(string a, string b) {
        int m = a.size(), n = b.size();
        if (!n) return 0;
        
        // include
        if (m >= n) {
            for (int i = 0; i <= m - n; i++) {
                if (a.substr(i, n) == b) return 1;
            }
        }
        
        // match a-suf with b-pre
        int res = repNum(a, b, 0); 
        
        string a_suf = "";
        for (int i = 1; i <= n; i++) {
            int pos = (m - i) % m; 
            pos = (pos >= 0) ? pos : pos + m;
            
            a_suf = a[pos] + a_suf;
            
            if (a_suf == b.substr(0, i)) res = min(res, repNum(a, b, i) + (i - 1) / m + 1);
        }
        
        if (res > 10000) return -1;
        return res;
    }
};
