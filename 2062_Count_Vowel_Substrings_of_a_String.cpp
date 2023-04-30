// https://leetcode.com/problems/count-vowel-substrings-of-a-string/
// string

class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char, int> vow;
        vow['a'] = 1; vow['e'] = 2; vow['i'] = 3; vow['o'] = 4; vow['u'] = 5;
        
        vector<int> fre(5);
        
        int len  = word.size(); if (len < 5) return 0;
        
        int res = 0;
        
        for (int i = 0; i < len - 4; i++) {
            if (!vow[word[i]]) continue;
            
            vector<int> fre(5);
            for (int j = i; j < len; j++) {
                if (!vow[word[j]]) break;
                
                fre[vow[word[j]] - 1]++;
                
                if (fre[0] && fre[1] && fre[2] && fre[3] && fre[4]) res++;
            }      
        }
        
        return res;

    }
};
