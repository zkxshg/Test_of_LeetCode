// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04
// Sorting

class Solution {
public:
    #define ll long long
    ll ub = 1e9 + 7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<ll> sArr;
        for (int i = 0; i < n; i++) {
            ll tem = 0;
            for (int j = i; j < n; j++) {
                tem = (tem + nums[j]) % ub;
                sArr.push_back(tem);
            }
        }

        sort(sArr.begin(), sArr.end());

        ll res = 0;
        for (int i = left - 1; i < right; i++) res = (res + sArr[i]) % ub;
        return res;
    }
};
