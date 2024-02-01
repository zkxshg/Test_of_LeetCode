// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/
// Sorting + Greedy

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int> > res(n / 3);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            int pos = i / 3;

            if (res[pos].empty()) res[pos].push_back(nums[i]);
            else {
                if (nums[i] - res[pos][0] > k) return {};
                else res[pos].push_back(nums[i]); 
            }
        }

        return res;
    }
};
