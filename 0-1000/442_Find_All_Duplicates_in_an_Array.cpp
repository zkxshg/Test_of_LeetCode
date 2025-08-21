// same to 41
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        int temp = 0;
        for (int i = 0; i < len; i++){
            while (nums[i] > 0 && nums[i] < (len + 1) &&  nums[(nums[i]-1)] != nums[i]) {
                temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
        }
        vector<int> result;
        for (int i = 0; i < len; i++){
            if (nums[i] != i + 1) result.push_back(nums[i]); 
        }
        return result;
        
    }
};
