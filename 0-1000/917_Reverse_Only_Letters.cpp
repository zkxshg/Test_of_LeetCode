// https://leetcode.com/problems/reverse-only-letters/
// two pointers

class Solution {
public:
    bool ifLetter(char c) {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        return false;
    }
    
    string reverseOnlyLetters(string s) {
        int n = s.size();
        
        int st = 0, en = n - 1;
        while (st < n && !ifLetter(s[st])) st++;
        while (en >= 0 && !ifLetter(s[en])) en--;
        
        while (st < en) {
            char t = s[st]; s[st] = s[en]; s[en] = t;
            
            st++; en--;
            
            while (st < n && !ifLetter(s[st])) st++;
            while (en >= 0 && !ifLetter(s[en])) en--;
        }
        
        return s;
    }
};
