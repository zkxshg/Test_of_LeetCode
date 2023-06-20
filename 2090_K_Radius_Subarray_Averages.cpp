// https://leetcode.com/problems/k-radius-subarray-averages/description/
// sliding window

class Solution {
public:
    #define ll long long

    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> res(n, -1);
        if (n < 2 * k + 1) return res;

        ll sw = 0;
        for (int i = 0; i < k; i++) sw += nums[i];

        for (int i = 0; i < n; i++) {
            if (i + k >= n) break;
            else sw += nums[i + k];

            if (i - k - 1 >= 0) sw -= nums[i - k - 1];
            
            if (i - k >= 0) res[i] = sw / (2 * k + 1);
        }

        return res;
    }
};
