class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        vector<int> money(nums.size(), -1);
        int result = maxMoney(nums, nums.size() - 1, money);
        return result;
    }
    int maxMoney(vector<int>& nums, int pos, vector<int>& money){
        if (pos == 0) {
            if (money[0] < 0) money[0] = nums[0];
            return money[0];
        } 
        if (pos == 1) {
            if (money[0] < 0) money[0] = nums[0];
            if (money[1] < 0) money[1] = max(nums[1], nums[0]);
            return money[1];
        }
        if (money[pos - 2] < 0) money[pos - 2] = maxMoney(nums, pos-2, money);
        if (money[pos - 1] < 0) money[pos - 1] = maxMoney(nums, pos-1, money);
        
        return max(nums[pos] + money[pos - 2], money[pos - 1]);
    }
};
