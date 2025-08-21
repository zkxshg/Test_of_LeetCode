// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Greedy
class Solution {
public:
    int minFlips(string s) {
        int n = s.size(); if (n < 2) return 0;
        //cout << n << endl;
        string s0 = "", s1 = "";
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                s0 += '1'; s1 += '0';
            }
            else {
                s0 += '0'; s1 += '1';
            }
        }
        
        int res = n, t0 = 0, t1 = 0;
        
        for (int j = 0; j < n; j++) {
            t0 += (s0[j] != s[j]);
            t1 += (s1[j] != s[j]);
        }
        
        res = min(t0, t1);;
        if (n % 2 == 0) return res;
        
        for (int j = n - 1; j >= 0; j--) {
            int tm = t0; t0 = t1; t1 = tm;
            
            if (s[j] == '1') {
                t0++; t1--;
            }
            else {
                t0--; t1++;
            }
            
            res = min(t0, res); res = min(t1, res);
        }

        
        return res;
    }
};
