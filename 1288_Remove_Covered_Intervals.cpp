// https://leetcode.com/problems/remove-covered-intervals
// two pointers
class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size(); if (len < 2) return len;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int pos = 0;
        while (pos < intervals.size()) {
            int right = intervals[pos][1];
            
            int nex = pos + 1;
            while (nex < intervals.size()) {
                if (right >= intervals[nex][1]) intervals.erase(intervals.begin() + nex);
                else nex++;
            }
            
            pos++;
        }
        
        return intervals.size();
    }
};
