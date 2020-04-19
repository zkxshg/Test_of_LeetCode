// binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return -1;
        if (len == 1 || nums[0] < nums.back()) return nums[0];
        int pos = forRot(nums, 0, len - 1);
        if (pos == nums.size() - 1) return nums.back();
        return nums[pos + 1];
    }
    
     int forRot(vector<int>& nums, int start, int last){
         if (start == last) return start;
         
         unsigned int k = (last + start) / 2;
         if (nums[k] > nums[k + 1]) return k;
         
         if (k == 0) return forRot(nums, 1, last);
         if (k == nums.size() - 1) return forRot(nums, 0, last - 1);
         
         if (nums[k] == nums.back() && nums[k] == nums[0]){
             for (int i = k + 1; i < nums.size(); i++){
                 if (nums[i] > nums[k]) return forRot(nums, i, last);
                 else if (nums[i] < nums[k]) return i - 1;
                 if (i == nums.size() - 1) return forRot(nums, start, k - 1);
             }
         }
         
         if (nums[k] <= nums.back()) return forRot(nums, start, k);
         return forRot(nums, k + 1, last);
    }
};
