class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        
        unordered_map<int, int> dict0;
        unordered_map<int, int> dict1;
        
        int counter = 1;
        for (int i = 0; i < len; i++){
            if (nums[i] == 0) {
                dict0[counter] = i;
                counter++;
            }
        }
        int len0 = counter - 1;
        
        counter = 1;
        for (int i = 0; i < len; i++){
            if (nums[i] == 1) {
                dict1[counter] = i;
                counter++;
            }
        }
        int len1 = counter - 1;
        
        if (len1 == len0) return len1 * 2;
        
        int maxL = 0;
        int d0 = 0;
        int d1 = 0;
        
        int pos = 0;
        int minL = min(len0, len1);
        int start = 1;
        
        while (pos < len && maxL < minL){
            
            for (int j = minL; j >= start; j--) {
                if (dict1[j + d1] > dict0[j + d0]){
                     if (j + d0 + 1 > len0 || dict1[j + d1] < dict0[j + d0 + 1]){
                         maxL = j;
                         break;
                     }
                }      
                else if (j + d1 + 1 > len1 || dict1[j + d1 + 1] > dict0[j + d0]) {
                    maxL = j;
                    break;
                }
            }
            
            start = maxL + 1;
            
            if (nums[pos] == 0) d0++; 
            else d1++;
            
            if (len0 - d0 == len1 - d1) {
                if (len0 - d0 > maxL) maxL = len0 - d0;
                break;
            }
            
            minL = min(len0 - d0, len1 - d1);
            pos++;
        }
        return maxL * 2;
    }
};
