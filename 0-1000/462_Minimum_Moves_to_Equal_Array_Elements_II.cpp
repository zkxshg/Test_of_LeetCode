// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// math
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len = nums.size(); if (len < 2) return 0;
        
        sort(nums.begin(), nums.end());
        
        int res = 0;
        if (len % 2) {
            int aim = nums[len / 2];
            for (int i : nums) res += abs(aim - i);  
        }
        else {
            int a1 = nums[len / 2 - 1], a2 = nums[len / 2];
            int r1 = 0, r2 = 0;
            for (int i : nums) {
                r1 += abs(a1 - i); r2 += abs(a2 - i);
            }  
            res = min(r1, r2);
        }
        
        return res;
    }
};
