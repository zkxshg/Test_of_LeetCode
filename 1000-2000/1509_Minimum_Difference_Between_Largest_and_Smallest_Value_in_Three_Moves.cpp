// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
// Greedy

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        
        int res = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= 3; i++) 
            for (int j = 0; j <= 3 - i; j++)
                res = min(res, nums[n - 1 - j] - nums[i]);
        return res;
    }
};
