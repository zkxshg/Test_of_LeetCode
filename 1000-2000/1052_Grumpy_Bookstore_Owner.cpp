// https://leetcode.com/problems/grumpy-bookstore-owner/?envType=daily-question&envId=2024-06-21
// Sliding Window

class Solution {
public:
    #define cus customers
    #define grp grumpy
    #define mnt minutes

    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = cus.size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!grp[i]) res += cus[i];
        }

        int max_tec = 0;
        for (int i = 0; i < mnt; i++) {
            if (grp[i]) max_tec += cus[i];
        }

        int tem = max_tec;
        for (int i = 1; i <= n - mnt; i++) {
            if (grp[i - 1]) tem -= cus[i - 1];
            if (grp[i + mnt - 1]) tem += cus[i + mnt - 1];
            max_tec = max(tem, max_tec);
        }

        return res + max_tec;
    }
};
