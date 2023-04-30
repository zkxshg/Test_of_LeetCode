class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() > 1){
            int len = nums.size();
            int temp = 0;
            int cou = 0;
            while (temp < len - cou){
                if (nums[temp] != 0) temp++;
                else{
                    for (int i = temp; i < len - cou - 1; i++) nums[i] = nums[i+1];
                    nums[len - cou - 1] = 0;
                    cou++;
                }
            }
        }
    }
};
