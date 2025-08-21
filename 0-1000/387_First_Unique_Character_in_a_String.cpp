// hash table
class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.size();
        if (len < 2) return len - 1;
        
        unordered_map<char, int> cDict;
        for (char str : s) cDict[str]++;
        
        for (int i = 0; i < len; i++) {
            if (cDict[s[i]] == 1) return i;
        }
        return -1;  
    }
};
