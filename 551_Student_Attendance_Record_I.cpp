// string
class Solution {
public:
    bool checkRecord(string s) {
        unordered_map<char, int> rec;
        for (char ch : s) rec[ch]++;
        if (rec['A'] > 1) return false;
        if (rec['L'] > 2) {
            for (int i = 1; i < s.size() - 1; i++) {
                if (s[i - 1] == s[i] && s[i + 1] == s[i] && s[i] == 'L' ) return false;
            }
        }
        return true;
    }
};
