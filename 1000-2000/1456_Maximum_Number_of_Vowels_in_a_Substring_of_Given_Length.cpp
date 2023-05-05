// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
// Sliding Window

class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a') return true;
        if (c == 'e') return true;
        if (c == 'i') return true;
        if (c == 'o') return true;
        if (c == 'u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.size(), res = 0, wRes = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) wRes++; 
        }
        res = wRes;

        for (int i = k; i < n; i++) {
            if (isVowel(s[i - k])) wRes--;
            if (isVowel(s[i])) wRes++;
            res = max(res, wRes);
        }
        return res;
    }
};
