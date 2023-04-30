// string
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool upper = false;
        bool lower = false;
        int len = word.size(); if (len <= 1) return true;
        
        if (ifLower(word[0])) lower = true;
        
        for (int i = 1; i < len; i++) {
            if (ifUpper(word[i])) upper = true;
            else lower = true;
            if (upper && lower) return false;
        }
        return true;
    }
    
    bool ifUpper(char ch) {
        if (ch >= 'A' && ch <= 'Z') return true;
        return false;
    }
    
    bool ifLower(char ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        return false;
    }
};
