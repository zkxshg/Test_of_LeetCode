// array + hash map
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size(); if (len == 1) return 1; 
        
        unordered_map<int, int> fre; int maxF = 0;
        for (int i : nums) {
            fre[i]++; maxF= max(maxF, fre[i]);
        }
        if (maxF == 1) return 1;
        
        vector<int> cand;
        for (auto& v : fre) 
            if (v.second == maxF) 
                cand.push_back(v.first);
        
        int res = len;
        for (int c : cand) {
            int st = find(nums.begin(), nums.end(), c) - nums.begin();
            int fre = 1, en = len - 1;
            for (int i = st + 1; i < len; i++) {
                if (nums[i] == c) fre++;
                if (fre == maxF) {
                    en = i; break;
                }
            }
            res = min(res, en - st + 1);
        }
        
        return res; 
    }
};
