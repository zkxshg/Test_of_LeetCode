// array: O(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(); if (n <= 1) return 0;
        
        vector<int> tMax(n); tMax[0] = nums[0];
        for (int i = 1; i < n; i++) tMax[i] = max(nums[i], tMax[i - 1]);
        
        vector<int> tMin(n); tMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) tMin[i] = min(nums[i], tMin[i + 1]);
        
        int st = 0, en = n - 1;
        while (st <= en && nums[st] == tMin[st]) st++;
        while (st <= en && nums[en] == tMax[en]) en--;
        
        return en - st + 1;
    }
};
