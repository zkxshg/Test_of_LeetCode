// DP
class Solution {
public:
     
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size(); if (len < 2) return nums[0];

        vector<int> sco(len); sco[0] = nums[0];
        
        int maxlessK = sco[0];
        for (int i = 1; i < len; i++) {
            if (i <= k) {
                maxlessK = max(maxlessK, sco[i - 1]);
                sco[i] = maxlessK + nums[i];
            }
            else {
                int tem = sco[i - 1];
                for (int j = 1; j <= k; j++) {
                    if (nums[i - j] > 0) {
                        tem = sco[i - j];
                        break;
                    }
                    else tem = max(tem, sco[i - j]);
                }
                sco[i] = tem + nums[i];
            }
        }
        
        return sco[len - 1];
    }
};
