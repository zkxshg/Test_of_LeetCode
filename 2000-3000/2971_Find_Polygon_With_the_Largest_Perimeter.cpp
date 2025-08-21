// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/?envType=daily-question&envId=2024-02-15
// Greedy + Prefix Sum

class Solution {
public:
    #define ll long long

    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ak = nums.back();

        vector<ll> preS(n); preS[0] = nums[0];
        for (int i = 1; i < n - 1; i++) preS[i] = preS[i - 1] + nums[i];

        for (int i = n - 1; i >= 2; i--) {
            if (preS[i - 1] > nums[i]) return preS[i - 1] + nums[i];
        }

        return -1;
    }
};
