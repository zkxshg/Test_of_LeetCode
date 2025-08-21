// DP
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size(); if (len < 3) return false;
        
        vector<int> tri; tri.push_back(nums[0]);
        for (int i = 0; i < len; i++) {
            int n = nums[i];
            
            for (int j = 0; j < tri.size(); j++) {
                if (n <= tri[j]) {
                    tri[j] = n;
                    break;
                }
                else if (j == tri.size() - 1) {
                    tri.push_back(n);
                    break;
                }
            }
            
            if (tri.size() >= 3) return true;
        }
        
        return false;
    }
};
