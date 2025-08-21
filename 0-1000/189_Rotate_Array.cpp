// reverse
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2) return;
        
        k = k % len;
        if (k == 0) return;
        int k1 = len - k;
        reverse(nums.begin(), nums.begin() + k1);
        reverse(nums.begin() + k1, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
