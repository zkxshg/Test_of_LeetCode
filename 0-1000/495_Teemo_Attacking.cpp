// array + pair<int,int>
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len = timeSeries.size(); 
        if (len < 1) return 0;
        if (len < 2) return duration;
        
        vector<pair<int,int> > timeLine;
        timeLine.push_back(make_pair(timeSeries[0], timeSeries[0] + duration));
        
        for (int i = 1; i < len; i++) {
            if (timeSeries[i] < timeLine.back().second) timeLine.back().second = timeSeries[i] + duration;
            else timeLine.push_back(make_pair(timeSeries[i], timeSeries[i] + duration));
        }
        
        int result = 0;
        for (pair<int,int> pr : timeLine) result += pr.second - pr.first;
        return result;
    }
};
