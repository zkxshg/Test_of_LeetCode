class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        for (int i = 0; i < len - 1; i += 2) {
            if (nums[i] != nums[i + 1]) return nums[i];
        }
        return nums[len - 1];
    }
};
