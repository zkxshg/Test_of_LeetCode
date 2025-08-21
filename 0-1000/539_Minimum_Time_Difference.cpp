// https://leetcode.com/problems/minimum-time-difference/
// sorting

class Solution {
public:
    int convert(string& current) {
        int h1 = 0, m1 = 0;
        h1 = current[0] - '0'; h1 = h1 * 10 + current[1] - '0';
        m1 = current[3] - '0'; m1 = m1 * 10 + current[4] - '0';
        
        int t1 = h1 * 60 + m1;
        return t1;
    }
    
    int findMinDifference(vector<string>& timePoints) {
        vector<int> tint;
        for (auto& s : timePoints) tint.push_back(convert(s));
        
        sort(tint.begin(), tint.end());
        
        int res = INT_MAX, n = tint.size();
        for (int i = 0; i < n - 1; i++) res = min(res, tint[i + 1] - tint[i]);
        res = min(res, tint[0] + 1440 - tint[n - 1]);
        
        return res;
    }
};
