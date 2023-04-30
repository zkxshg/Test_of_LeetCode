// https://leetcode.com/problems/long-pressed-name/
// two pointers

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(), t = typed.size();
        
        int npos = 0, tpos = 0;
        while (npos < n && tpos < t) {
            if (name[npos] == typed[tpos]) {
                npos++; tpos++;
            }
            else if (npos > 0 && typed[tpos] == name[npos - 1]) tpos++;
            else return false;
        }

        if (npos < n) return false;
        
        if (tpos < t) 
            for (int i = tpos; i < t; i++)
                if (typed[i] != name.back())
                    return false;
    
        return true;
    }
};
