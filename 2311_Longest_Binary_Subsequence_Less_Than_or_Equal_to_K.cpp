/ /https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/
// Greedy

class Solution {
public:
    int str2int(string bi) { 
        int res = 0;
        for (char c : bi) res = res * 2 + (c - '0'); // cout << bi << "=" << res << endl;
        return res;
    }
    
    int longestSubsequence(string s, int k) {
        int n = s.size();
        
        int lv = 0, tk = k;
        while (tk) { tk /= 2; lv++;} // cout << "lv = " << lv << endl;
        
        int pos = 0, rm = 0;
        while (pos < n) {
            if (s[pos] - '0') {
                if (n - pos > lv) {
                    s[pos] = '0'; rm++;
                }
                else {
                    int tem = str2int(s.substr(pos));
                    
                    if (tem <= k) break;
                    else {
                        s[pos] = '0'; rm++;
                    }
                }
            }
    
            pos++;
        }
        
        // cout << rm << endl;
        return n - rm;
    }
};
