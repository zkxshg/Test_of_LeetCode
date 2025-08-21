// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
// Greedy

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        
        int maxV = INT_MIN, maxP = 0, minV = INT_MAX, minP = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxV) {
                maxV = nums[i]; maxP = i;
            }
            if (nums[i] < minV) {
                minV = nums[i]; minP = i;
            }
        }
        
        
        int res = min(max(maxP + 1, minP + 1), max(n - maxP, n - minP));
        
        return min(res, min(maxP, minP) + 1 + (n - max(minP, maxP)));
    }
};
