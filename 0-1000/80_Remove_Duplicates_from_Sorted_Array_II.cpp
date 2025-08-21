// linear scan: if (nums[i] == nums[j]) { counter += 1; if (counter >= 2){ exist = 1; break; } }
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        
        int result = 1;
        for (int i = 1; i < len; i++){
            bool exist = 0;
            int counter = 0;
            
            for (int j = 0; j < result; j++){
                if (nums[i] == nums[j]) {
                    counter += 1;
                    if (counter >= 2){
                        exist = 1;
                        break;
                    }
                }
            }
            
            if(!(exist)){
                nums[result] = nums[i];
                result++;
            }
        }
        return result;
        
    }
};
