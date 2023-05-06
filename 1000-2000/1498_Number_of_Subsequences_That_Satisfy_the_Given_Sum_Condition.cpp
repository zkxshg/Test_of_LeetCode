// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
// binary search

class Solution {
public:
    #define ll long long 
    ll ub =  1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<ll> p2(n); p2[0] = 1;
        for (int i = 1; i < n; i++) p2[i] = (p2[i - 1] * 2) % ub;

        ll res = 0;
        for (int i = 0; i < n; i++) {
            int st = nums[i], diff = target - st;
            if (diff < st) break;
            int en = upper_bound(nums.begin() + i, nums.end(), diff) - nums.begin();
            int num = en - i - 1;

            res = (res + p2[num]) % ub;
        }
        return res;
        
    }
};
