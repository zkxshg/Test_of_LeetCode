// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// string

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int res = -1, n1 = sentence.size(), n = searchWord.size(), pos = 0, cou = 0;
        
        string word = "";
        while (pos < n1) {
            if (sentence[pos] == ' ' || pos == n1 - 1) {
                cou++;
                
                if (pos == n1 - 1) word += sentence[pos];

                if (word.size() >= n && word.substr(0, n) == searchWord) return cou;
                
                word = "";
            }
            else word += sentence[pos];
            
            pos++;
        }
        
        return -1;
    }
};
