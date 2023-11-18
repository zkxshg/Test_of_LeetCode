// https://leetcode.com/problems/greatest-common-divisor-of-strings/
// string

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        
        string res = "";
        
        for (int i = 1; i <= n1; i++) {
            if (i > n2) break;
            
            if (n1 % i || n2 % i) continue;
            
            string div = str1.substr(0, i);
            
            bool ifDiv = true;
            for (int j1 = 0; j1 < n1; j1 += i) {
                if (str1.substr(j1, i) != div) {
                    ifDiv = false; break;
                }
            }
            
            if (!ifDiv) continue;
            
            for (int j2 = 0; j2 < n2; j2 += i) {
                if (str2.substr(j2, i) != div) {
                    ifDiv = false; break;
                }
            }
            
            if (ifDiv) {
                res = div;
            }
        }
        
        return res;
    }
};
