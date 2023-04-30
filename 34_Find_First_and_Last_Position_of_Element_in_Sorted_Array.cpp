// Binary search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if (nums.size() == 0) return result;
        
        vector<int> tarPos;
        int min = nums.size()+1;
        int max = -1;
        firstVersion(target, nums, &min, &max, 0, nums.size()-1);
        if (min > nums.size()) min = -1;

        result[0] = min;
        result[1] = max;
        return result;
    }
    
    void firstVersion(int target, vector<int>& nums, int * min, int * max, int start, int least) {
        if (start == least) {
            if (nums[start] == target) updateK(min, max, start);
        }
        else{
            unsigned int k = (least + start) / 2;
            if (nums[k] == target) {
                updateK(min, max, k);
                firstVersion(target, nums, min, max, start, k);
                firstVersion(target, nums, min, max, k+1, least);        
            }
            else if(nums[k] > target) firstVersion(target, nums, min, max, start, k);
            else firstVersion(target, nums, min, max, k+1, least);
        }
    }
    
    void updateK(int * min, int * max, int kpos){
        if (kpos < *min) *min = kpos;
        if (kpos > *max) *max = kpos;
    }
    
};
