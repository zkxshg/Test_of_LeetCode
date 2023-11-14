// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
// prefix sum + hash table

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        vector<int> st(26, -1); vector<int> en(26, -1); st[s[0] - 'a'] = 0;

        vector<vector<int> > ps(n, vector<int>(26)); ps[0][s[0] - 'a'] = 1;

        for (int i = 1; i < n; i++) {
            int ch = s[i] - 'a';

            for (int c = 0; c < 26; c++) ps[i][c] = ps[i - 1][c];
            ps[i][ch]++;

            if (st[ch] < 0) st[ch] = i;
            else en[ch] = i;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            int ist = st[i], ien = en[i];

            if (ist < 0 || ien < 0) continue;

            for (int j = 0; j < 26; j++) {
                if (ps[ien - 1][j] - ps[ist][j] > 0) res++;
            }
        }

        return res;
    }
};
