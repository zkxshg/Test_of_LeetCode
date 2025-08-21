// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// array

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), m = n / 2;
        vector<int> pos; vector<int> neg;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        
        for (int i = 0; i < n; i += 2) {
            nums[i] = pos[i / 2]; nums[i + 1] = neg[i / 2];
        }
        
        return nums;
    }
};
