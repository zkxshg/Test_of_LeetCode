// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
// hash table

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();

        vector<int> fre(26);

        for (auto& s : words) {
            for (char c : s) fre[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (fre[i] % n != 0) return false;
        }

        return true;
    }
};
