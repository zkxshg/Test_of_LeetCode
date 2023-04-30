// https://leetcode.com/problems/number-of-valid-words-in-a-sentence/
// string

class Solution {
public:
    bool isLetter(char c) {
        if (c <= 'z' && c >= 'a') return true;
        return false;
    }
    int countValidWords(string sentence) {
        int res = 0, n = sentence.size();
        
        bool word = true, conti = false, hyp = false, punc = false;
        for (int i = 0; i < n; i++) {
            char c = sentence[i];
            
            if (c == ' ') {
                if (word && conti) res++;
                word = true; conti = false; hyp = false, punc = false;
            }
            else if (!isLetter(c)) {
                conti = true;
                
                if (c <= '9' && c >= '0') word = false;
                else if (c == '-') {
                    if (!hyp && i > 0 && isLetter(sentence[i - 1]) && 
                        i < n - 1 && isLetter(sentence[i + 1])) hyp = true;
                    else word = false;
                }
                else if (punc || (i < n - 1 && sentence[i + 1] != ' ')) word = false;
                else punc = true;
            }
            else conti = true;

            if (i == n - 1 && c != ' ' && word) res++;
        }
        
        return res;
    }
};
