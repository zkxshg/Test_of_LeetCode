// linear scan the left/right intervals and relative positions
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int lInd = -1, lPos = 0, rInd = -1, rPos = 0;
        
        int len = intervals.size();
        if (len == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        for (int i = 0; i < len; i++) {  
            if (lInd < 0) {
                if (intervals[i][0] > newInterval[0]) {
                    lInd = i; lPos = -1;
                } else if (intervals[i][1] >= newInterval[0]) {
                    lInd = i; lPos = 0;
                }
            }
            
            if (rInd < 0) {
                if (intervals[i][0] > newInterval[1]) {
                    rInd = i; rPos = -1;
                } else if (intervals[i][1] >= newInterval[1]) {
                    rInd = i; rPos = 0;
                }
            }
            
            if (rInd >= 0 && lInd >= 0) break;
        }
        
        
        if (lInd < 0 && newInterval[0] > intervals[len - 1][1]) {
            lInd = len - 1; lPos = 1;
        }
        
        if (rInd < 0 && newInterval[1] > intervals[len - 1][1]) {
            rInd = len - 1; rPos = 1;
        }
        
        
        if (lPos == 1 || (rInd == 0 && rPos == -1)) {
            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end());
            return intervals;
        }
        
        if (lInd == rInd && lPos == rPos) {
            if (rPos == 0) return intervals;
            // rPos == -1
            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end());
            return intervals;
        }
        
        
        int startPos = lInd, endPos = rInd - 1;
        if (lPos == 0) newInterval[0] = intervals[lInd][0];
        if (rPos == 0) {
            newInterval[1] = intervals[rInd][1];
            endPos = rInd;
        } else if (rPos == 1) endPos = rInd;
        
        intervals.erase(intervals.begin() + startPos, intervals.begin() + endPos + 1);
        intervals.push_back(newInterval);
        
        sort(intervals.begin(), intervals.end());
        return intervals;
    }
};
