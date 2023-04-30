// brute force
class Solution {
public:
    static bool cmp(string& a, string& b) {
        return a.size() < b.size();
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        //sort(wordlist.begin(), wordlist.end(), cmp);
        
        int Qlen = queries.size();
        vector<string> res(Qlen);
        
        for (int i = 0; i < Qlen; i++) {
            string qu = queries[i];
            
            string cor1 = ""; string cor2 = ""; string same = "";
            
            bool getMisOne = false, getVolMis = false;
            for (string word : wordlist) {
                if (word.size() != qu.size()) continue;
                
                if (word == qu) {
                    same = word; break;
                }
                
                bool CaseMis = false, VoMis = false;
                if (!getMisOne) {
                    bool spMis = true;
                    
                    for (int j = 0; j < word.size(); j++) {
                        if (qu[j] != word[j]) {
                            if (abs(qu[j] - word[j]) == 32) CaseMis = true; 
                            else if (ifVowel(qu[j]) && ifVowel(word[j])) VoMis = true; 
                            else { spMis = false; break; }  
                        }
                    }
                    
                    if (spMis) { 
                        if (CaseMis) { getMisOne = true; cor1 = word; }
                        if (!getVolMis && VoMis) { cor2 = word; getVolMis = true;}
                    }
                }
            }
            
            if (!same.empty()) res[i] = same;
            else if (!cor1.empty()) res[i] = cor1;
            else res[i] = cor2;
        }
        
        return res;
    }
    
    bool ifVowel(char c) {
        if (c == 'a' || c == 'A') return true;
        if (c == 'e' || c == 'E') return true;
        if (c == 'i' || c == 'I') return true;
        if (c == 'o' || c == 'O') return true;
        if (c == 'u' || c == 'U') return true;
        return false;
    }
};
