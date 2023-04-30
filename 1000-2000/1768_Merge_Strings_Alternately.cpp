// https://leetcode.com/problems/merge-strings-alternately/description/
// string

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        
        string res = "";
        int pos = 0;
        while (pos < n1 && pos < n2) {
            res += word1[pos]; res += word2[pos];
            pos++;
        }

        if (pos < n1) res += word1.substr(pos);
        else if (pos < n2) res += word2.substr(pos);

        return res;
    }
};
