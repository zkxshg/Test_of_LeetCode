// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
// Greedy + Sorting

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(), res = 0;

        sort(piles.begin(), piles.end());

        int num = 0;
        while (num < n / 3) {
            res += piles[n - 2 - 2 * num];
            num++;
        }

        return res;
    }
};
