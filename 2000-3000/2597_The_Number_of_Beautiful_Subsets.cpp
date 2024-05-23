// https://leetcode.com/problems/the-number-of-beautiful-subsets/?envType=daily-question&envId=2024-05-23
// Backtracking

class Solution {
public:
    void backtrack(vector<int>& nums, int k, int idx, int& count, vector<int>& cnt) {
        if (idx == nums.size()) return;

        for (int i = idx; i < nums.size(); ++i) {
            // Check if absolute difference exists
            if (nums[i] >= k && cnt[nums[i] - k] > 0) continue; 

            cnt[nums[i]]++; count++;
            backtrack(nums, k, i + 1, count, cnt);
            cnt[nums[i]]--;
        }
    }

    int beautifulSubsets(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        vector<int> cnt(nums.back() + 1, 0); // Initialize array to record visited nodes
        backtrack(nums, k, 0, count, cnt);
        return count;
    }
};
