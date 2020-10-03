// hash map
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size(); if (len < 2) return 0;
        
        unordered_map<int, int> dict;
        for (int num : nums) dict[num]++;
        
        int result = 0;
        
        if (k == 0) {
            for (auto& it : dict) {
                if (it.second > 1) result++;
            }
            return result;
        }
        
        for (auto& it : dict) {
            int a = it.first;
            if (dict.count(a + k)) result++;
        }
        
        return result; 
    }
};
