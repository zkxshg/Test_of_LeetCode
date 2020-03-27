// missing = n * (n + 1) / 2 - sum(nums); 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int sum = 0;
        for (int i = 0; i < len; i++) sum += nums[i];
        int sumAll = len * (len+1) / 2;
        return sumAll - sum;
    }
};
