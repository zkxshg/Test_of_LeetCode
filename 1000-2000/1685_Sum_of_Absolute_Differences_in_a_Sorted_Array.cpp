// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
// Prefix Sum

class Solution {
public:
    #define ll long long

    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<ll> preS(n); preS[0] = nums[0];
        for (int i = 1; i < n; i++) preS[i] = preS[i - 1] + nums[i];

        vector<int> res(n); 
        res[0] = preS[n - 1] - preS[0] - (n - 1) * nums[0];

        for (int i = 1; i < n; i++) {
            ll lres = (i - (n - 1 - i)) * nums[i];
            lres += preS[n - 1] - preS[i];
            lres -= preS[i - 1];
            res[i] = lres;
        }

        return res;
    }
};
