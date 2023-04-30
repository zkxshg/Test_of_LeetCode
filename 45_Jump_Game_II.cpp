// https://leetcode.com/problems/jump-game-ii/
// DP + Greedy

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> R(n, n + 1);
        
        R[0] = 0;
        
        for (int i = 0; i < n; i++) {
            int M = nums[i];
            
            int s = 1;
            while (i + s < n && s <= M) {
                R[i + s] = min(R[i + s], R[i] + 1);
                s++;
            }
        }
        
        return R[n - 1];
    }
};
