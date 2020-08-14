// hash table
class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        if (len < 2) return len;
        
        unordered_map<char, int> sDict;
        for (int i = 0; i < len; i++) sDict[s[i]]++;
        
        int result = 0, odd = 0;
        for(auto it : sDict) {
            if (it.second % 2 == 0) result += it.second;
            else {
                odd = 1;
                result += it.second - 1;
            }
        }
        return result + odd;
    }
};
