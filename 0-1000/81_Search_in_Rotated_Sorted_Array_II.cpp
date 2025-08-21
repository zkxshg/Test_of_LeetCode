// 154. Find Minimum in Rotated Sorted Array II + 33. Search in Rotated Sorted Array
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return false;
        if (nums[0] == target || nums.back() == target) return true;
        if (len == 1) return false;
        
        if (nums.back() > nums[0]) return biSearch(nums, target, 0, len - 1) > -1;
        
        int pos = forRot(nums, 0, len - 1);
        if (pos == len - 1) return biSearch(nums, target, 0, len - 1) > -1;
        else if (pos == 0) return biSearch(nums, target, 1, len - 1) > -1;
        
        if (nums.back() > target) return biSearch(nums, target, pos + 1, len - 1) > -1;
        
        return biSearch(nums, target, 0, pos) > -1;    
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
    
    int biSearch(vector<int>& nums, int target, int start, int last){
        if (start == last) {
            if (nums[start] == target) return start;
            else return -1;
        }
        
        unsigned int k = (last + start) / 2;
        if (nums[k] == target) return k;
        else if(nums[k] > target) return biSearch(nums, target, start, k);
        
        return biSearch(nums, target, k+1, last);
    }
};
