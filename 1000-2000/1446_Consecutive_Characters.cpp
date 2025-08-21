// https://leetcode.com/problems/consecutive-characters/
// hash map
class Solution {
public:
    int maxPower(string s) {
        unordered_map<char, int> powers;
        for (char ch : s) powers[ch] = 0;
        powers[s[0]] = 1;
            
        int res = 1, len = s.size();
        for (int i = 1; i < len; i++) {
            char ch = s[i];
            if (ch == s[i - 1]) {
                powers[ch]++;
                res = max(res, powers[ch]);
            }
            else powers[ch] = 1; 
        }
        
        return res;
    }
};
