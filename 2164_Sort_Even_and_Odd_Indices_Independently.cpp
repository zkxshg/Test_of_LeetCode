// https://leetcode.com/problems/sort-even-and-odd-indices-independently/
// sorting

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd; vector<int> even;
        for (int i = 0; i < n; i += 2) {
            even.push_back(nums[i]);
            if (i + 1 < n) odd.push_back(nums[i + 1]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());
        for (int i = 0; i < n; i += 2) {
            nums[i] = even[i / 2];
            if (i + 1 < n) nums[i + 1] = odd[i / 2];
        }
        return nums;
    }
};
