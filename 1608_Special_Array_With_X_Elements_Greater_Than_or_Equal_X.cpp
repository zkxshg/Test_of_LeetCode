// sort
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        if (nums[0] >= len) return len;
        
        for (int i = len - 1; i >= 1; i--) {
            if (nums[len - i] >= i && nums[len - i - 1] < i) return i;
        }
        
        return -1;
        
    }
};
