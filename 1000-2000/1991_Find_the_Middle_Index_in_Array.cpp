// https://leetcode.com/problems/find-the-middle-index-in-array/
// prefix sum

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size(), pos = 0, left = 0, right = accumulate(nums.begin() + 1, nums.end(), 0);
        if (n < 2) return 0;
        while (pos < n) {
            if (left == right) return pos;
            left += nums[pos]; 
            if (pos + 1 < n) right -= nums[pos + 1];
            pos++;
        }
            
        return -1;
    }
};
