// Use nums[index] to record index + 1;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 1;
        if (len == 1){
            if (nums[0] == 1) return 2; 
            else return 1;
        }
        
        int temp = 0;
        for (int i = 0; i < len; i++){
            while (nums[i] > 0 && nums[i] < (len + 1) &&  nums[(nums[i]-1)] != nums[i]) {
                temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
        }
        for (int i = 0; i < len; i++){
            if (nums[i] != i + 1) return i + 1; 
        }
        return len + 1;
    }
};
