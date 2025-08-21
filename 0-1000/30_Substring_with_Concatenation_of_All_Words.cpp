// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// sliding window + Rabin–Karp algo

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> s2i;
        
        vector<int> fre; 
        
        int ind = 1;
        for (string w : words) {
            if (!s2i[w]) {
                s2i[w] = ind; 
                fre.push_back(1);
                ind++;
            }
            else fre[s2i[w] - 1]++;
        }
        
        int wlen = words[0].size(), n = words.size(), slen = s.size();
        
        int en = slen - wlen * n;
        if (en < 0) return {};
        
        vector<int> res;
        for (int i = 0; i <= en; i++) {
            bool conc = true;
            
            vector<int> tf = fre;
            
            for (int j = 0; j < n * wlen; j += wlen) {
                string subs = s.substr(i + j, wlen);

                if (!s2i[subs]) {
                    conc = false; break;
                }
                else {
                    if (!tf[s2i[subs] - 1]) {
                        conc = false; break;
                    }
                    else tf[s2i[subs] - 1]--;
                }
            }
            
            if (conc) res.push_back(i);
        }
        
        return res;    
    }
};
