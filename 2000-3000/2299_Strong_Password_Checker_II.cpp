// https://leetcode.com/problems/strong-password-checker-ii/
// string

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size(); if (n < 8) return false;
        
        unordered_map<char, int> specCh;
        string schar = "!@#$%^&*()-+"; for (char c : schar) specCh[c]++;
        
        bool low = false, up = false, dig = false, spec = false; 
        for (int i = 0; i < n; i++) {
            if (password[i] >= 'a' && password[i] <= 'z') low = true;
            else if (password[i] >= 'A' && password[i] <= 'Z') up = true;
            else if (password[i] >= '0' && password[i] <= '9') dig = true;
            else if (specCh[password[i]]) spec = true;
            
            if (i > 0 && password[i - 1] == password[i]) return false;                                    
        }
        
        if (low && up && dig && spec) return true;
        return false;
    }
};
