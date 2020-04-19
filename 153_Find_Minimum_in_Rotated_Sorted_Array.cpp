// binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return -1;
        if (len == 1 || nums[0] < nums.back()) return nums[0];
        int pos = forRot(nums, 0, len - 1);
        return nums[pos + 1];   
    }
    
    int forRot(vector<int>& nums, int start, int last){
        if (start == last) return start;
        unsigned int k = (last + start) / 2;
        if (nums[k] > nums[k + 1]) return k;
        else if (nums[k] < nums.back()) return forRot(nums, start, k);
        return forRot(nums, k + 1, last);
    }
    
};
