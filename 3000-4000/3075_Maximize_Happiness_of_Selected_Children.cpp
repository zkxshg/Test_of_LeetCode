// https://leetcode.com/problems/maximize-happiness-of-selected-children/?envType=daily-question&envId=2024-05-09
// Greedy + Sorting

class Solution {
public:
    #define ll long long

    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());

        ll res = 0;
        for (int i = 0; i < k; i++) {
            if (happiness.back() <= i) break;

            res += happiness.back() - i;
            happiness.pop_back();
        }

        return res;
    }
};
