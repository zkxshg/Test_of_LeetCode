// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/
// Greedy
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        
        bool get = false;
        
        vector<int> R(51, 0);
        // for (int i = 0; i < left; i++) R[i] = 1;
        
        for (auto& v : ranges) 
           for (int i = v[0]; i <= v[1]; i++)
               if (!R[i]) R[i] = 1;
        
        for (int i = left; i <= right; i++)
            if (!R[i])
                return false;
        
        return true;
        
        
    }
};
