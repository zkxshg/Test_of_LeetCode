// https://leetcode.com/problems/reverse-prefix-of-word/?envType=daily-question&envId=2024-05-01
// string

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        string res;
        string pre = "";
        for (int i = 0; i < n; i++) {
            pre = word[i] + pre;

            if (word[i] == ch) {
                res = pre + word.substr(i + 1);
                break;
            }
        }
        if (res.empty()) return word;
        return res;
        
    }
};
