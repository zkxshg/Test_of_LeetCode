// https://leetcode.com/problems/longest-common-prefix/
// stepwise calcu comPre
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) return "";
        if (len == 1) return strs[0];
        
        string comPre = strs[0];
        int counter = 1;
        while (counter < len){
            int slen = comPre.size();
            int pos = 0;
            while (pos < slen){
                if (comPre[pos] == strs[counter][pos]) pos++;
                else break;
            }
            comPre = comPre.substr(0, pos);
            if (comPre == "") return "";
            counter++;
        }
        return comPre;
    }
};
