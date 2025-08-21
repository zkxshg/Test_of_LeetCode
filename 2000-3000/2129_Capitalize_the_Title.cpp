// https://leetcode.com/problems/capitalize-the-title/
// string

class Solution {
public:
    string capitalizeTitle(string title) {
        string res = "";
        
        string tem = "";
        for (char c : title) {
            if (c == ' ') {
                if (tem.empty()) res += ' ';
                else {
                    if (tem.size() <= 2) {
                        for (int i = 0; i < tem.size(); i++)
                            tem[i] = (tem[i] >= 'a' && tem[i] <= 'z') ?  tem[i] : tem[i] + ('a' - 'A');
                    }  
                    else {
                        tem[0] = (tem[0] >= 'A' && tem[0] <= 'Z') ?  tem[0] : tem[0] + ('A' - 'a');
                        for (int i = 1; i < tem.size(); i++)
                            tem[i] = (tem[i] >= 'a' && tem[i] <= 'z') ?  tem[i] : tem[i] + ('a' - 'A');
                    }
                    res += tem; res += ' ';
                    tem = "";
                }
            }
            else tem += c;
        }
        
        if (!tem.empty()) {
            if (tem.size() <= 2) {
                for (int i = 0; i < tem.size(); i++)
                    tem[i] = (tem[i] >= 'a' && tem[i] <= 'z') ?  tem[i] : tem[i] + ('a' - 'A');
            }  
            else {
                tem[0] = (tem[0] >= 'A' && tem[0] <= 'Z') ?  tem[0] : tem[0] + ('A' - 'a');
                for (int i = 1; i < tem.size(); i++)
                    tem[i] = (tem[i] >= 'a' && tem[i] <= 'z') ?  tem[i] : tem[i] + ('a' - 'A');
            }
            res += tem;
        }
        
        return res;
    }
};
