// https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// two pointers + greedy
class Solution {
public:
    int balancedString(string s) {
        int len = s.size(), lenper = len / 4;
        
        unordered_map<char, int> chs;
        chs['Q'] = 0; chs['E'] = 0; chs['W'] = 0; chs['R'] = 0;
         
        int st = 0, en = len - 1;
        while (st < len && st < en) {
            if (chs[s[st]] >= lenper) {
                st--;
                break;
            }
            else {
                chs[s[st]]++;
                st++;
            }
        }
        
        while (en >= 0 && en > st) {
            if (chs[s[en]] >= lenper) {
                en++;
                break;
            }
            else {
                chs[s[en]]++;
                en--;
            }
        }
        
        if (st == en) return 0;
        
        int res = en - st - 1;
        while (st >= 0 && en > st) {
            while (chs[s[en - 1]] >= lenper && st >= 0) {
                chs[s[st]]--; st--; 
            }
            
            while (chs[s[en - 1]] < lenper && en > st) {
                en--;
                chs[s[en]]++; 
            }
            
            res = min(res, en - st - 1);
        }
        return res;
    }
};
