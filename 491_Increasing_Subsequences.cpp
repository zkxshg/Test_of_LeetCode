// https://leetcode.com/problems/increasing-subsequences/
// Bit mask + Hash map

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int len = nums.size();

        int maskLen = 1 << len;
        
        vector<vector<int> > result;
        
        unordered_map<string, int> dict;
        
        for (int i = 0; i < maskLen; i++) {
            bitset<32> bits(i);
            if (bits.count() < 2) continue;
            
            vector<int> tem; string res = "";
            
            for (int j = 0; j < len; j++) {
                if ((bits[j]) && (tem.empty() || tem.back() <= nums[j])) {
                    tem.push_back(nums[j]); 
                    res += to_string(nums[j]); res += ",";
                }
            }
            
            if (tem.size() > 1 && !dict[res]) {
                result.push_back(tem);
                dict[res]++;
            }
        }
        
        return result;
    }
};
