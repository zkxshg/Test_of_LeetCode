// https://leetcode.com/problems/keyboard-row/
// hash table

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        
        unordered_map<char, int> kb;
        for (char c : row1) {
            kb[c] = 1; kb[c + ('A' - 'a')] = 1;
        }
        for (char c : row2) {
            kb[c] = 2; kb[c + ('A' - 'a')] = 2;
        }
        for (char c : row3) {
            kb[c] = 3; kb[c + ('A' - 'a')] = 3;
        }
        
        vector<string> res;
        for (string& w : words) {
            int h = kb[w[0]];
            
            bool oneRow = true;
            for (int i = 1; i < w.size(); i++) {
                if (kb[w[i]] != h) {
                    oneRow = false; break;
                } 
            }
                
            if (oneRow) res.push_back(w);
        }
        
        return res;
    }
};
