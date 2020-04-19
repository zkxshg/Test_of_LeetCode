class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return -1;
        if (len == 1){
            if (nums[0] == target) return 0;
            else return -1;
        }
        if (nums.back() > nums[0]) return biSearch(nums, target, 0, len - 1);
        int pos = forRot(nums, 0, len - 1);
        if (nums.back() >= target) return biSearch(nums, target, pos + 1, len - 1);
        return biSearch(nums, target, 0, pos);    
    }
    
    int forRot(vector<int>& nums, int start, int last){
        if (start == last) return start;
        unsigned int k = (last + start) / 2;
        if (nums[k] > nums[k + 1]) return k;
        else if (nums[k] < nums.back()) return forRot(nums, start, k);
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
