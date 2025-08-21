// string::size_type pos = s.find(' '); pos = s.find(' ', pos+1);
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        if (len == 0) return 0;
        if (s == " ") return 0;
        else if (len == 1) return 1;
        
        int start = 0;
        string::size_type pos = s.find(' ');
        
        int end = pos;
        if (end >= len || end < 0) end = len;
        
        while (pos < len && pos >= 0){
            if((pos + 1) < len && s[pos+1] != ' ') {
                start = pos+1;
                end = s.find(' ', pos+1);
                if (end >= len || end < 0) end = len;
            }
            pos = s.find(' ', pos+1);
        }
        return (end - start);
    }
};
