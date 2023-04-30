// hash table
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return false;
        
        unordered_map<int, int> couDict;
        for (int i = 0; i < len; i++) {
            couDict[nums[i]]++;
            if (couDict[nums[i]] > 1) return true;
        }
        return false;
    }
};
