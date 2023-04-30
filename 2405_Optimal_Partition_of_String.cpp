// https://leetcode.com/problems/optimal-partition-of-string/description/
// hash table

class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), res = 0;
        vector<int> cnt(26);

        for (char c : s) {
            if (cnt[c - 'a'] > 0) {
                res++;
                fill(cnt.begin(), cnt.end(), 0);
            }
            cnt[c - 'a']++;
        }

        return res + 1;
    }
};
