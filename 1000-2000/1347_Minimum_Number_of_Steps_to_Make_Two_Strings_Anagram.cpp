// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
// Greedy

class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        vector<int> sf(26);
        vector<int> tf(26);

        for (char c : s) sf[c - 'a']++;
        for (char c : t) tf[c - 'a']++;

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (sf[i] < tf[i]) res += (tf[i] - sf[i]);
        }

        return res;
    }
};
