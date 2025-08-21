// https://leetcode.com/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2023-11-13
// string

class Solution {
public:

    bool ifVowel(char c) {
        if (c == 'a' || c == 'A') return true;
        if (c == 'e' || c == 'E') return true;
        if (c == 'i' || c == 'I') return true;
        if (c == 'o' || c == 'O') return true;
        if (c == 'u' || c == 'U') return true;
        return false;
    }

    string sortVowels(string s) {
        int n = s.size();

        vector<int> Vos;
        vector<int> order;

        for (int i = 0; i < n; i++) {
            if (ifVowel(s[i])) {
                Vos.push_back(s[i]);
                order.push_back(i);
            }
        }

        sort(Vos.begin(), Vos.end());
        for (int i = 0; i < order.size(); i++) s[order[i]] = Vos[i];

        return s;
    }
};
