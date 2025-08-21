// 2410. Maximum Matching of Players With Trainers
// Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
// Lang: C++
// Date: 2025-08-21 21:02:09.828 UTC

class Solution {
public:
    #define ps players
    #define ts trainers

    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = ps.size(), n = ts.size();

        sort(ps.begin(), ps.end());
        sort(ts.begin(), ts.end());

        int pst = 0, tst = 0, res = 0;
        while (pst < m && tst < n) {
            if (ps[pst] <= ts[tst]) {
                res++; pst++;
            }

            tst++;
        }

        return res;
    }
};
