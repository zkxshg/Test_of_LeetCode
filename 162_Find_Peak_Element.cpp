// https://leetcode.com/problems/find-peak-element/
// Binary search

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(); if (n < 2) return 0;
        
        if (nums[0] > nums[1]) return 0;
        else if (nums[n - 1] > nums[n - 2]) return n - 1;
        
        int st = 0, en = n - 1;
        while (st < en) {
            int mid = (st + en) / 2;
            
            if (mid > 0 && nums[mid] < nums[mid - 1]) en = mid;
            else if (mid < n - 1 && nums[mid] < nums[mid + 1]) st = mid + 1;
            else return mid;
            
            if (st == en) return st;
        }
        
        return 0; 
    }
};
