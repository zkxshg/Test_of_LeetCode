// brute-force DP
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len == 0) return 0;
        if (len == 1) return 1;
        
        int result = 1;
        string lss = s.substr(0,1);
        int pos = 1;
        bool noRep = true;
        while (pos < len){
            noRep = true;
            for (int i = 0; i < lss.size(); i++){
                if (lss[i] == s[pos]){
                    noRep = false;
                    break;
                }
            }
            if (noRep){
                lss += s[pos];
                result++;
                pos++;
            }
            else break;
        }
        
        int lengthNext = lengthOfLongestSubstring(s.substr(1, len-1));
        
        if (result > lengthNext) return result;
        else return lengthNext;
    }
};
