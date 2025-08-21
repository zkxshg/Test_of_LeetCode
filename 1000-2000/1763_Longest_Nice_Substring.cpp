// brute force: O(n^3)
class Solution {
public:
    string longestNiceSubstring(string s) {
        int len = s.size();
        
        string res = "";
        int maxL = 0;
        
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                string tar = s.substr(i, j - i + 1);
                
                if (ifNice(tar) && tar.size() > maxL) {
                    res = tar;
                    maxL = tar.size();
                }
            }
        }
        
        return res;
    }
    
    bool ifNice(string s) {
        unordered_map<char, int> dict;
        for (char c : s) dict[c]++;
        for (char c : s) {
            char o;
            if (c >= 'a' && c <= 'z') o = c - 32;
            else o = c + 32;
            
            if (!dict[o]) return false;
        }
        return true;
    }
};
