class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> fre(26); int maxV = 0;
        for (char c : s) {
            fre[c - 'a']++; maxV = max(maxV, fre[c - 'a']);
        }
        for (int i : fre)
            if (i && i != maxV) return false;
        return true;
    }
};
