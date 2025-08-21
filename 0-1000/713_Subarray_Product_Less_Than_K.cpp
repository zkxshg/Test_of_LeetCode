// two pointers
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        if (k <= 1 || len == 0) return 0;
        
        unordered_map<int, int> mulDict;
        
        int cou = 0;
        int tem = 0;
        for (int i = len - 1; i >= 0; i--) {
  
            if (nums[i] == 1) {
                if (i == len - 1) {
                    mulDict[i] = 1;
                    cou++;
                    continue;
                }
                cou += mulDict[i + 1] + 1;
                mulDict[i] = mulDict[i + 1] + 1;
                continue;
            }
            
            if (nums[i] >= k) continue;
            else  tem = 1;
            
            int multi = nums[i];
            for (int j = i + 1; j < len; j++){
                multi *= nums[j];
                if (multi >= k) break;
                else tem++;
            }
            
            mulDict[i] = tem;
            cou += tem;
        }
        return cou;
  
    }
};
