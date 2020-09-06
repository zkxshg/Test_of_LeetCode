// 5507_Replace_All_?_to_Avoid_Consecutive_Repeating_Characters.cpp
class Solution {
public:
    string modifyString(string s) {
        int len = s.size();
        if (len < 2) {
            if (s[0] == '?') return "a";
            return s;
        }
                
        for (int i = 0; i < len; i++) {
            if (s[i] == '?') {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (i == 0) {
                        if (s[1] == ch) continue;
                    } else if (i == len -1) {
                        if (s[i - 1] == ch) continue;
                    } else if (s[i - 1] == ch || s[i + 1] == ch) continue;
                    
                    s[i] = ch;
                    break;
                }  
            }
        }
        
        return s;
    }
};
