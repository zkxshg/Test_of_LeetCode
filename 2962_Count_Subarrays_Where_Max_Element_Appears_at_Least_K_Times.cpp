// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
// sliding window

class Solution {
public:
    #define ll long long
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());

        vector<int> idx;
        for (int i = 0; i < n; i++) if (nums[i] == m) idx.push_back(i);

        if (idx.size() < k) return 0;

        ll res = 0;
        int st = 0, en = k - 1, ni = idx.size(); // cout << ni << endl;
        while (en < ni) {
            int ist = idx[st], ien = idx[en];

            ll lb = ist - ((st > 0) ? idx[st - 1] : -1);
            ll ub = n - ien;
            // cout << lb << ":" << ub << endl;

            res += lb * ub;

            st++; en++;
        }

        return res;
        
    }
};
