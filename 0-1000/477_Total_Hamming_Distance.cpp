// https://leetcode.com/problems/total-hamming-distance/
// Bit Maniputation + Combination

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> oneNum(32);
        
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < 32; j++) 
                if (nums[i] & (1 << j)) oneNum[j]++;
        
        int res = 0;
        for (int i = 0; i < 32; i++) res += oneNum[i] * (n - oneNum[i]);
        
        return res;
    }
};
