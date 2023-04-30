// two pointer
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return true;
        
        int cou = 0;
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                cou++;
                if (cou > 1) return false;
                if (i > 0 && nums[i - 1] > nums[i + 1] && i < len - 2 && nums[i] > nums[i + 2]) return false;
        }
        return true;  
    }
};
