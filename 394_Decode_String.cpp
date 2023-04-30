// stack + two points
class Solution {
public:
    string decodeString(string s) {
        int len = s.size(); if (len < 4) return s;
        
        string res = "";
        
        int pos = 0;
        while (pos < len && s[pos] >= 'a' && s[pos] <= 'z') res += s[pos++];
        
        int left = s.find('[', pos), right = s.find(']', pos);
        
        while (pos < len && left >= 0) {
            // get the frequency
            int fre = 0, lev = 0;
            pos = left - 1;
            while (pos >= 0 && s[pos] >= '0' && s[pos] <= '9') fre += pow(10, lev++) * (s[pos--] - '0');
            
            string subs;
            if (right < s.find('[', left + 1)) subs = s.substr(left + 1, right - left - 1);
            else {
                int subL = s.find('[', left + 1);
                while (subL >= 0 && subL < right) {
                    right = s.find(']', right + 1);
                    subL = s.find('[', subL + 1);
                }
                
                subs = decodeString(s.substr(left + 1, right - left - 1));
            }
          
            for (int i = 0; i < fre; i++) res += subs;
 
            pos = right + 1;
            
            while (pos < len && s[pos] >= 'a' && s[pos] <= 'z') res += s[pos++];
            if (pos >= len) break;
            
            left = s.find('[', pos), right = s.find(']', pos);
        }
        
        return res;
    }
};
