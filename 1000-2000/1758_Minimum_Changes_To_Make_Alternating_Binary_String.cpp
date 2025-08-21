// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// string

class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), even = 0, odd = 0; // 010101 : even; 101010 : odd;
        for (int i = 0; i < n; i += 2) {
            if (s[i] == '0') odd++;
            else even++;
            
            if (i + 1 < n) {
                if (s[i + 1] == '0') even++;
                else odd++;
            }
            else break;
        }
        
        return min(odd, even);
    }
};
