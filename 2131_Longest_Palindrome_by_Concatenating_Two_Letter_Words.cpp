// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
// hash table

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        
        set<string> ws;
        
        unordered_map<string, int> fre;
        for (string& s : words) {
            fre[s]++; ws.insert(s);
        }
        
        int res = 0; bool odd = false;
        
        for (string s1 : ws) {
            if (!fre[s1]) continue;
            
            string s2 = ""; s2 += s1[1]; s2 += s1[0];
            //cout << fre[s1] << ":" << fre[s2] << endl;
            
            if (s1 == s2) {
                res += (fre[s1] / 2) * 4;
                
                if (!odd && fre[s1] % 2) {
                    res += 2; odd = true;
                }
                
                fre[s1] = 0;
            }
            else {
                res += 4 * min(fre[s1], fre[s2]);
            
                fre[s1] = 0; fre[s2] = 0;
            } 
        }
        
        return res;
    }
};
