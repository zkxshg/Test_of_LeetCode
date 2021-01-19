// DP
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(); if (len < 2) return s;
        
        int maxL = 1, maxS = 0, maxE = 0;
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1]) {
                int st = i, en  = i + 1;
                while (st >= 0 && en < len) {
                    if (s[st] == s[en]) {
                        if (en - st + 1 > maxL) {
                            maxL = en - st + 1; maxS = st; maxE = en;
                        }
                        st--; en++;
                    }
                    else break;
                }
            }
            
            if (i > 0 && s[i - 1] == s[i + 1]) {
                int st = i - 1, en  = i + 1;
                while (st >= 0 && en < len) {
                    if (s[st] == s[en]) {
                        if (en - st + 1 > maxL) {
                            maxL = en - st + 1; maxS = st; maxE = en;
                        }
                        st--; en++;
                    }
                    else break;
                }
            }
        }
        
        return s.substr(maxS, maxL);
        
    }
};
