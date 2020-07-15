// Two pointers
class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        if (len < 1) return s;

        vector<string> wordList;
        int pos, temp;
        if (s[0] != ' ') pos = 0;
        else {
            while (s[pos] == ' ') pos++;
        }
        
        while (pos < len && pos != s.npos) {
            temp = pos;
            pos = s.find(" ", pos + 1);
            
            if (pos == s.npos || pos >= len) wordList.push_back(s.substr(temp));
            else {
                wordList.push_back(s.substr(temp, pos - temp));
                while (pos < len && s[pos] == ' ') pos++;
            }
        }

        string result = "";
        int wLen = wordList.size();
        for (int i = 0; i < wLen; i++) {
            result += wordList[wLen - i - 1];
            if (i < wLen - 1) result += " ";
        }
        
        return result;
    }
};
