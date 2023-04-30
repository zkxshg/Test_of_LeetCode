// https://leetcode.com/problems/patching-array/
// greedy

class Solution {
public:
    #define ll long long
    int minPatches(vector<int>& nums, int n) {  
       // First linear scan the nums
        int res = 0, pos = 0; 
        
        if (nums[0] != 1) res++;
        else pos++;
        
        ll temS = 1;
        while (pos < nums.size()) {
            if (temS + 1 < nums[pos]) {
                temS += temS + 1; res++;
            }
            else {
                temS += nums[pos]; pos++;
            }
     
            if (temS >= n) break;
        }
      
         // Greedy to expand nums
        while (temS < n) {
            temS += temS + 1; res++;
        }
        
        return res;
    }
};
