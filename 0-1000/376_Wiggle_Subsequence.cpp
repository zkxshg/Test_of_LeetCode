// greedy
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size(); if (len < 2) return len;
        
        
        int pos = 1;
        while (pos < len && nums[pos] == nums[pos - 1]) pos++;
        if (pos == len) return 1;
        
        bool posi = false;
        if (nums[pos] - nums[pos - 1] > 0) posi = true;
        else posi = false;
        pos++;
        
        int res = 2; 
        while (pos < len) {
            if (nums[pos] != nums[pos - 1]) {
                if (nums[pos] > nums[pos - 1] && !posi) {
                    res++; posi = true;
                }
                else if (nums[pos] < nums[pos - 1] && posi) {
                    res++; posi = false;
                }
            }
            pos++;
        }
        
        return res;
    }
};
