// https://leetcode.com/problems/two-sum/
// hash_table

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        unordered_map<int, int> ind;
        
        for (int i : nums) ind[i]++;
        
        for (int i = 0; i < n; i++) {
            int ni = nums[i];
            if (ind[target - ni]) {
                if (target - ni == ni && ind[ni] < 2) continue;
                else {
                    int nj = target - ni;
                    for (int j = 0; j < n; j++) 
                        if (nums[j] == nj && j != i)
                            return {i,j};
                }   
            }
        } 
        
        return {-1, -1};
        
    }
};
