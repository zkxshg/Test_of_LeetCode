// Greedy + two pointers
class Solution {
public:
    
    static int cmp(vector<int> a, vector<int> b) {
        return (a[1] < b[1] ? 1 : 0);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (len < 2) return 0;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int pre = 0, nex = 1, result = 0;
        while (nex < len) {
            if (intervals[pre][1] <= intervals[nex][0]) pre = nex;
            else result++;
            
            nex++;
        }
        
        return result;
    }
};
