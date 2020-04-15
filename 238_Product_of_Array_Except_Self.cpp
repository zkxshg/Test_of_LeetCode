// result[i] = forw[i - 1] * backw[i + 1];
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return nums;
        vector<int> forw(len);
        vector<int> backw(len);
        
        int multi = 1;
        for (int i = 0; i < len; i++){
            multi *= nums[i];
            forw[i] = multi;
        }
        multi = 1;
        for (int i = len - 1; i >= 0; i--){
            multi *= nums[i];
            backw[i] = multi;
        }
        
        vector<int> result(len);
        result[0] = backw[1];
        result[len - 1] = forw[len - 2];
        for (int i = 1; i < len - 1; i++) result[i] = forw[i - 1] * backw[i + 1];
        return result;
    }
};
