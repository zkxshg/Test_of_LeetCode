// two pointers
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int len = nums.size(); if (len < 2) return nums[0];
        
        int res = 0;
        for (int i = 0; i < len; i++) {
            int sum = nums[i];
            
            int j = i + 1;
            while (j < len && nums[j] > nums[j - 1]) {
                sum += nums[j]; j++;
            } 
            res = max(res, sum);
        }
        
        return res;
    }
};
