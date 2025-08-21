// 3136. Valid Word
// Link: https://leetcode.com/problems/valid-word/
// Lang: C++
// Date: 2025-08-21 21:01:47.840 UTC

class Solution {
public:
    bool ifVow(char c) {
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        }
        else if (c >= 'A' && c <= 'Z') {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        }
        return false;
    }

    bool isValid(string word) {
        if (word.size() < 3) return false;
        
        bool valid = true, haveVow = false, haveCons = false;

        for (char c : word) {
            if (c >= '0' && c <= '9') continue;

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                if (ifVow(c)) haveVow = true;
                else haveCons = true;
            }
            else {
                valid = false; break;
            }
        }

        if (valid && haveVow && haveCons) return true;
        return false;
    }
};
