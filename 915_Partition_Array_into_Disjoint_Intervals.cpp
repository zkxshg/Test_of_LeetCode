// https://leetcode.com/problems/partition-array-into-disjoint-intervals/
// sort

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int> > np;
        for (int i = 0; i < n; i++) np.push_back(make_pair(nums[i], i));
        
        sort(np.begin(), np.end());
        
        int maxL = -1;
        for (int i = 0; i < n; i++) {
            maxL = max(maxL, np[i].second);
            if (maxL <= i) return i + 1;
        }
        
        return n;
    }
};
