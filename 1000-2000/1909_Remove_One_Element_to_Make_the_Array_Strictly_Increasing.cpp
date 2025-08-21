// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
// brute-force

class Solution {
public:

    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            bool con = true;
            
            int pre = 0;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                
                if (nums[j] <= pre) {
                    con = false; break;
                }
                else pre = nums[j];
            }
            
            if (con) return true;
        }
        
        return false;
        
    }
};
