// https://leetcode.com/problems/sum-of-subarray-ranges/
// array

class Solution {
public:
    #define ll long long
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        ll res = 0;
        
        for (int i = 0; i < n; i++) {
            int maxV = nums[i], minV = nums[i];
            for (int j = i; j < n; j++) {
                maxV = max(maxV, nums[j]);
                minV = min(minV, nums[j]);
                res += maxV; res -= minV;
            }
        }
        
        return res;
    }
};
