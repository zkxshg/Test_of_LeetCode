// https://leetcode.com/problems/sliding-window-maximum/
// divide and conquer
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size(); if (len == 1 || k == 1) return nums;
        
        vector<int> result;
        vector<int> left(len); 
        vector<int> right(len);
        
        for (int i = 0; i < len; i += k) {
            if (i + k > len) {
                int maxA = INT_MIN;
                for (int j = len - 1; j >= i; j--) {
                    maxA = max(maxA, nums[j]);
                    right[j] = maxA;
                }
                
                int maxB = INT_MIN;
                for (int j = i; j < len; j++) {
                    maxB = max(maxB, nums[j]);
                    left[j] = maxB;
                }
                break;
            }
            
            int maxA = INT_MIN;
            for (int j = i + k - 1; j >= i; j--) {
                maxA = max(maxA, nums[j]);
                right[j] = maxA;
            }
            
            int maxB = INT_MIN;
            for (int j = i; j < i + k; j++) {
                maxB = max(maxB, nums[j]);
                left[j] = maxB;
            }
        }
        
        for (int i = 0; i < len - k + 1; i++) result.push_back(max(right[i], left[i + k - 1]));
        
        return result;
    }
};
