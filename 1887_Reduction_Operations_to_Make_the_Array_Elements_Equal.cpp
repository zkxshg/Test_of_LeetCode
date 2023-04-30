// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
// greedy + RLE
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size(); if (n < 2) return 0;
        
        sort(nums.begin(), nums.end());
        
        vector<pair<int, int> > RLE; RLE.push_back(make_pair(nums[0], 1));
        for (int i = 1; i < n; i++) {
            if (nums[i] == RLE.back().first) RLE.back().second++;
            else RLE.push_back(make_pair(nums[i], 1));
        }
        
        int res = 0, m = RLE.size();
        if (m < 2) return 0;
        
        for (int i = 1; i < m; i++) res += RLE[i].second * i;
        
        return res;
        
    }
};
