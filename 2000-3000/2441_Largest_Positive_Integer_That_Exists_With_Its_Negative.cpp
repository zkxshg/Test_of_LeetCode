// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/?envType=daily-question&envId=2024-05-02
// Hash Table

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); // Convert nums to unordered_set for O(1) lookup
        int maxK = -1;
        for (int num : nums) {
            if (num > 0 && numSet.count(-num)) { // If current num is positive and its negative counterpart exists
                maxK = max(maxK, num); // Update maxK if necessary
            }
        }
        return maxK == -1 ? -1 : maxK;
    }
};
