// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/?envType=daily-question&envId=2024-08-06
// Greedy

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        vector<int> fre(26);
        for (char c : word) fre[c - 'a']++;

        vector<int> lfre;
        for (int i = 0; i < 26; i++) {
            if (fre[i]) lfre.push_back(fre[i]);
            // if (fre[i]) cout << char('a' + i) << ":" << fre[i] << endl;
        }
        sort(lfre.begin(), lfre.end());
        

        int res = 0, cost = 1, lnum = 0;
        while (!lfre.empty()) {
            res += lfre.back() * cost;
            lfre.pop_back();

            lnum++;
            if (lnum >= 8) {
                cost++; lnum = 0;
            }
        }

        return res;
    }
};
