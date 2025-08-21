// https://leetcode.com/problems/split-array-into-consecutive-subsequences/
// RLE + Heap + DP

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        
        // RLE coding
        vector<pair<int, int> > RLE; RLE.push_back({nums[0], 1});
        for (int i = 1; i < n; i++) {
            if (nums[i] == RLE.back().first) RLE.back().second++;
            else RLE.push_back({nums[i], 1});
        }
        // for (auto& p : RLE) cout << p.first << ":" << p.second << ","; cout << endl;
        
        n = RLE.size();
        vector<int> pre; 
        for (int i = 0; i < RLE[0].second; i++) pre.push_back(1);
        
        for (int i = 1; i < n; i++) {
            vector<int> tem;
            
            int suc = RLE[i].first, cou = RLE[i].second;
            
            // Non-consecutive
            if (suc - RLE[i - 1].first > 1) {
                if (!pre.empty() && pre[0] < 3) return false;
                
                pre.clear();
                for (int j = 0; j < cou; j++) pre.push_back(1);
                
                continue;
            }
            
            // Consecutive
            if (cou <= pre.size()) {
                int m = pre.size(), pos = 0;
                for (int j = 0; j < cou; j++) tem.push_back(pre[j] + 1);
                
                if (cou < pre.size() && pre[cou] < 3) return false;
            }
            else {
                for (int j = 0; j < cou - pre.size(); j++) tem.push_back(1);
                for (int j : pre) tem.push_back(j + 1);
            }
            
            pre = tem;
            
            // for (int i : pre) cout << i << ","; cout << endl;
        }
        
        if (!pre.empty() && pre[0] < 3) return false;
        
        return true;
    }
};
