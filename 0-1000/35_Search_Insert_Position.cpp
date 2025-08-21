// binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) {
            if (nums[0] < target ) return 1;
            else return 0;
        }
        
        int start = 0;
        int end = len - 1 ;
        while (end - start >= 0){
            if (start == end){
                if (target > nums[end]) return end+1;
                else return end;
            }
            if (end - start == 1){
                if (target > nums[end]) return end+1;
                else if (target <= nums[start]) return start;
                else return end;
            }
            int k = start + (end - start) / 2;
            if (target == nums[k]) return k;
            else if (target > nums[k]) start = k;
            else end = k;
        } 
        
        return 0;
    }
};
