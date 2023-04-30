// https://leetcode.com/problems/wiggle-sort-ii/
// sorting

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> res;
        
        int st = n / 2 - 1, en = n - 1; if (n % 2) st++;
        
        while(res.size() < n) {
            res.push_back(nums[st]); st--;
            
            if (res.size() < n) {
                res.push_back(nums[en]); en--;
            }
        }
        
        nums = res;
    }
};
