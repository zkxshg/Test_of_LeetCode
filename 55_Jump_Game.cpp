// Greedy back forward update  
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return true;
        int lastPos = len - 1;
        while (lastPos > 0) {
            bool skip = false;
            for (int i = lastPos -1; i >= 0; i--){
                if (lastPos - i <= nums[i]){
                    skip = true;
                    lastPos = i;
                    break;
                }
            }
            if (!skip) return false;
        }
        return true;
    }
};
