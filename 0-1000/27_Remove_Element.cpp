// linear scan: if (nums[i] == val) { for (int j = i; j < len - 1; j++) nums[j] = nums[j+1];
// nums[len - 1] = -1;
// result--;}
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) return 0;
        
        int result = len;
        int i = 0;
        while(i < len){
            if (nums[i] == val) {
                for (int j = i; j < len - 1; j++) nums[j] = nums[j+1];
                nums[len - 1] = -1;
                result--;
            }
            else i++;
        }
        return result;
    }
};
