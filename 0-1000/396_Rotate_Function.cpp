// https://leetcode.com/problems/rotate-function/
// DP

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sm = 0;
        for (int i : nums) sm += i;
        
        int maxF = 0; for (int i = 0; i < n; i++) maxF += i * nums[i]; // F(0)
        int nexF = maxF;
        
        for (int i = 1; i < n; i++) {
            nexF += sm; nexF -= n * nums[n - i];
            maxF = max(maxF, nexF);
        }
        
        return maxF;
    }
};
