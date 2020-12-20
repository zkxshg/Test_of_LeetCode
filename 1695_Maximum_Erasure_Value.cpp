// two points
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int len = nums.size(); if (len < 2) return nums[0];
        
        unordered_map<int, int> fre;
        
        int st = 0, en = 0, res = 0, maxRes = 0;
        while (en < len) {
            fre[nums[en]]++;
            
            if (fre[nums[en]] > 1) {
                while (fre[nums[en]] > 1) {
                    fre[nums[st]]--;
                    res -= nums[st];
                    st++;
                }
            }
            
            res += nums[en];
            maxRes = max(maxRes, res);
            
            en++;
        }
        
        return maxRes; 
    }
};
