// https://leetcode.com/problems/check-if-the-sentence-is-pangram/
// map
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> fre(26);
        for (char ch : sentence) fre[ch - 'a']++;
        for (int i : fre) 
            if (i < 1) return false;
        return true;
    }
};
