// DP + hash map
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size(); if (len == 1) return false;
        
        int sum = 0;
        for (int i : nums) sum += i;
        if (sum % 2 == 1) return false;
        int aim = sum / 2;
        
        unordered_map<int, int> sumDict;
        if (nums[0] == aim) return true;
        sumDict[nums[0]] = 1;
        
        for (int i = 1; i < len; i++) {
            vector<int> addI;
            for (auto& v : sumDict) {
                int add = v.first + nums[i];
                if (add == aim) return true;
                addI.push_back(add);
            }
            for (int ad : addI) sumDict[ad]++;  
            sumDict[nums[i]]++;
        }
        
        return false; 
    }
};
