// forward / backward + posMax / absMax
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        int posMax = nums[0];
        int absMax = nums[0];
        int maxV = INT_MIN;
        
        for (int i = 1; i < nums.size(); i++){
            if (maxV < posMax) maxV = posMax;
            
            if (nums[i] == 0){
                posMax = 0;
                absMax = 0;
            }
            else if(nums[i] > 0){
                if (!posMax) posMax = nums[i];
                else posMax *= nums[i];
                
                if (!absMax) absMax = nums[i];
                else absMax *= nums[i];
            }
            else {
                if (!absMax) absMax = nums[i];
                else absMax *= nums[i];
                
                if (absMax > 0) posMax = max(posMax, absMax);
                else posMax = 0;
            }
        }
        if (maxV < posMax) maxV = posMax;
        
        posMax = nums[nums.size() - 1];
        absMax = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--){
            if (maxV < posMax) maxV = posMax;
            
            if (nums[i] == 0){
                posMax = 0;
                absMax = 0;
            }
            else if(nums[i] > 0){
                if (!posMax) posMax = nums[i];
                else posMax *= nums[i];
                
                if (!absMax) absMax = nums[i];
                else absMax *= nums[i];
            }
            else {
                if (!absMax) absMax = nums[i];
                else absMax *= nums[i];
                
                if (absMax > 0) posMax = max(posMax, absMax);
                else posMax = 0;
            }
        }
        if (maxV < posMax) maxV = posMax;
        
        return maxV;
        
        
    }
};
