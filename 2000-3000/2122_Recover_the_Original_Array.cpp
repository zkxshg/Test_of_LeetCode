// https://leetcode.com/problems/recover-the-original-array/
// sorting

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n2 = nums.size();
        
        unordered_map<int, int> dict;
        for (int i : nums) dict[i]++;
        
        sort(nums.begin(), nums.end());
        
        int n = n2 / 2;
        vector<int> res(n);
        for (int i = 1; i < n2; i++) {
            int k = nums[i] - nums[0];
            if (k % 2 || k <= 0) continue;
            
            unordered_map<int, int> temp = dict;
            
            bool rec = true; int cou = 0;
            for (int i = 0; i < n2; i++) {
                if (temp[nums[i]]) {
                    temp[nums[i]]--;
                    
                    if (temp[nums[i] + k]) {
                        temp[nums[i] + k]--;
                        res[cou] = nums[i] + k / 2; cou++;
                    }
                    else {
                        rec = false; break;
                    }
                }
                else continue;
            }
            
            if (rec && cou >= n) break;
        }
        
        return res;
    }
};
