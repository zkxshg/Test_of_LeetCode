// https://leetcode.com/problems/shifting-letters/
// DP

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size(), num = 0;
        for (int i = n - 1; i >= 0; i--) {
            num = (num + shifts[i]) % 26;
            s[i] = 'a'+ (s[i] - 'a' + num) % 26; 
        }
        return s;
    }
};
