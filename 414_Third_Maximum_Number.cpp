// hash table
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return *max_element(nums.begin(), nums.end());
        
        vector<int> threeMax;
        
        for (int i = 0; i < len; i++) {
        
            if (threeMax.size() < 3) {
            
                bool cont = false;
                for (int j = 0; j < threeMax.size(); j++) {
                    if (nums[i] == threeMax[j]) {
                        cont = true;
                        break;
                    }
                }
                if (cont) continue;
                
                threeMax.push_back(nums[i]);
                if (threeMax.size() == 3) sort(threeMax.begin(), threeMax.end(), greater<int>());
            }
            else {
                if (nums[i] >= threeMax[0]) {
                    if (nums[i] == threeMax[0]) continue;
                    threeMax[2] = threeMax[1];
                    threeMax[1] = threeMax[0];
                    threeMax[0] = nums[i];
                }
                else if (nums[i] >= threeMax[1]) {
                    if (nums[i] == threeMax[1]) continue;
                    threeMax[2] = threeMax[1];
                    threeMax[1] = nums[i];
                }
                else if (nums[i] >= threeMax[2]) {
                    if (nums[i] == threeMax[2]) continue;
                    threeMax[2] = nums[i];
                }
            }
        }
        
        if (threeMax.size() < 3) return *max_element(threeMax.begin(), threeMax.end());
        
        return threeMax[2];
    }
};
