// two pointers
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int len = nums.size(); if (len < 3) return 0;
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for (int i = 0; i < len - 2; i++) {
            for (int j = i + 1; j < len - 1; j++) {
                int sum2 = nums[i] + nums[j];
                int pos = j + 1;
                while (pos < len && nums[pos] < sum2) {
                    res++; pos++;
                }
            }
        }
        return res; 
    }
};
