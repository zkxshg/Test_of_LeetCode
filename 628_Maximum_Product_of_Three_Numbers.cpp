class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3) return nums[0]*nums[1]*nums[2];
        int result = 1;
        
        int negnum = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < 0) negnum++;
            if (negnum > 1) break;
        }
        
        auto maxPosition = max_element(nums.begin(), nums.end());
        int pos = maxPosition - nums.begin();
        result *= nums[pos];
        nums.erase(nums.begin()+pos);
        
        int posMax = result;
        vector<int> nums1 = nums;
        for (int i = 0; i < 2; i++){ 
            auto maxPosition = max_element(nums1.begin(), nums1.end());
            int pos = maxPosition - nums1.begin();
            posMax *= nums1[pos];
            nums1.erase(nums1.begin()+pos);
        }
        
        int negMax = INT_MIN;
        if (negnum > 1){
            negMax = result;
            for (int i = 0; i < 2; i++){
                auto maxPosition = min_element(nums.begin(), nums.end());
                int pos = maxPosition - nums.begin();
                negMax *= nums[pos];
                nums.erase(nums.begin()+pos);
            }  
        }
        
        if (posMax < negMax) return negMax;
        return posMax;
    }

};
