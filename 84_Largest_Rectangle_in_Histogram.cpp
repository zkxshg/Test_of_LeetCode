// stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size(); 
        if (len == 0) return 0; if (len == 1) return heights[0];
        
        vector<pair<int, int> > recs; recs.push_back(make_pair(heights[0], 1));
        
        int res = 0;
        for (int i = 1; i < len; i++) {
            int h = heights[i], num = 1;
            
            while (!recs.empty() && recs.back().first > h) {
                res = max(res, recs.back().first * recs.back().second);
                num = max(num, recs.back().second + 1);
                recs.pop_back(); 
            }
            
            for (int j = 0; j < recs.size(); j++) recs[j].second += 1;
            
            if (recs.empty() || recs.back().first != h) recs.emplace_back(make_pair(h, num));
        }
        
        for (int j = 0; j < recs.size(); j++) res = max(res, recs[j].first * recs[j].second);
        
        return res;
        
    }
};
