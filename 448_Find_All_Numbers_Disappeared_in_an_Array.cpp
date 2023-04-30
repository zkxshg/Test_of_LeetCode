// same to 41. First Missing Positive
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        if (nums.size() == 0) return result;
        if (nums.size() == 1) {
            result.push_back(1);
            return result;
        }
        int temp = 0;
        for (int i = 0; i < nums.size(); i++){
            while (nums[i] != nums[nums[i] - 1]) {
                temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            } 
        }
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != i + 1) result.push_back(i+1);
        }
        return result;
    }
};
