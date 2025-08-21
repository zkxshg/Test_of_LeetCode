// https://leetcode.com/problems/verifying-an-alien-dictionary/
// map
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int len = words.size(); if (len < 2) return true;
        
        vector<int> dict(26);
        for (int i = 0; i < 26; i++) dict[order[i] - 'a'] = i;
        
        for (int i = 0; i < len - 1; i++) 
            if (!compNewOrder(words[i], words[i + 1], dict))
                return false;
        
        return true;
    }
    
    bool compNewOrder(string a, string b, vector<int>& dict) {
        int alen = a.size(), blen = b.size(); 
        for (int i = 0; i < alen; i++) {
            if (i >= blen) return false;
            if (dict[a[i] - 'a'] < dict[b[i] - 'a']) return true;
            else if (dict[a[i] - 'a'] > dict[b[i] - 'a']) return false;
        }
        return true;
    }
    
    
};
