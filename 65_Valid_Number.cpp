// https://leetcode.com/problems/valid-number/
// string

class Solution {
public:
    bool isDigit(char c) {
        if (c <= '9' && c >= '0') return true;
        return false;
    }
    
    bool ifDec(string& s, int st, int en) {
        if (st > en) return false;
        
        // check first if sign
        int pos = st; 
        if (s[st] == '+' || s[st] == '-') pos++;
        else if (!isDigit(s[st]) && s[st] != '.') return false;
        
        // case 3
        if (s[pos] == '.') {
            pos++;
            
            if (pos > en) return false; // e.g. -.e9
            
            while (pos <= en) {
                if (!isDigit(s[pos])) return false; // e.g. -.-1e9
                pos++;
            }
        }
        else {
            while (pos <= en && isDigit(s[pos])) pos++;
            
            if (pos > en) return false; // without "." -9e1
            
            if (s[pos] != '.') return false; //  false char -9-.9e1
            
            // case 1
            if (pos == en) return true; // -9.e1
            
            // case 2
            for (int i = pos + 1; i <= en; i++)
                if (!isDigit(s[i])) return false; // -9.-9e1
            
        }
        
        return true;
    }
    
    bool isInt(string& s, int st, int en) {
        if (st > en) return false;
        
        int pos = st; 
        
        if (s[st] == '+' || s[st] == '-') pos++;
        else if (!isDigit(s[st])) return false;
        
        if (pos > en) return false; // no digit
        
        for (int i = pos; i <= en; i++)
            if (!isDigit(s[i])) return false;
        
        return true;
    }
    
    bool isNumber(string s) {
        int n = s.size();
        
        int epos = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                epos = i; break;
            }
        }
        
        if (epos < 0) return (ifDec(s, 0, n - 1) || isInt(s, 0, n - 1));
        
        return ((ifDec(s, 0, epos - 1) || isInt(s, 0, epos - 1)) && isInt(s, epos + 1, n - 1));
    }
};
