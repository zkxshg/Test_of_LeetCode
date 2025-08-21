// https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/
// Greedy

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), pos = 0, rm = 0, loc = 0; 
        
        while (pos < n) {
            if (pos + 1 < n && nums[pos] == nums[pos + 1] && !((pos + loc) % 2)) {
                int cont = 1;
                while (pos + cont < n && nums[pos] == nums[pos + cont]) {
                    rm++; cont++;
                }
                
                pos = pos + cont; 
                if (!(cont % 2)) loc = 1 - loc;
            }
            else pos++;
        }
        
        if ((n - rm) % 2) return rm + 1;
        return rm;
    }
};
