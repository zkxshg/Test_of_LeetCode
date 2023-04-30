// https://leetcode.com/problems/maximum-number-of-words-you-can-type/
// map

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        
        vector<string> word;
        string s = "";
        for (int i = 0; i < n; i++) {
            if (text[i] == ' ') {
                word.push_back(s);
                s = "";
            }
            else s += text[i];
            
            if(i == n - 1 && !s.empty()) word.push_back(s);
        }
        
        unordered_map<char, bool> bl;
        for (char c : brokenLetters) bl[c] = true;
        
        int res = 0;
        for (string& w : word) {
            bool broken = false;
            for (char c : w) {
                if (bl[c]) {
                    broken = true; break;
                }
            }
            if (!broken) res++;
        }
        
        return res;
    }
};
