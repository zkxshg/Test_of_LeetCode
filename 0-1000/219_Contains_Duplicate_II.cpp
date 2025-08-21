// Hash Table
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2) return false;
        if (k == 0) return false;
        
        unordered_map<int, int> posDict;
        for (int i = 0; i < len; i++) posDict[nums[i]] = -1;
        
        for (int i = 0; i < len; i++) {
            if (posDict[nums[i]] < 0) posDict[nums[i]] = i;
            else {
                if (i - posDict[nums[i]] <= k) return true;
                else posDict[nums[i]] = i;
            }
        }
        return false;
    }
};
