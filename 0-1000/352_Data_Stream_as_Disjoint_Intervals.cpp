// https://leetcode.com/problems/data-stream-as-disjoint-intervals/
// design + hash map

class SummaryRanges {
public:
    int up;
    unordered_map<int, int> axis;
    
    SummaryRanges() {
        axis.clear(); up = 0;
    }
    
    void addNum(int val) {
        if (axis.count(val) == 0) {
            axis[val] = val;
            if (axis.count(val - 1) != 0) axis[val - 1] = val;
            if (axis.count(val + 1) != 0) axis[val] = val + 1;
            up = max(up, val);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int pos = 0;
        while (pos <= up) {
            if (axis.count(pos) != 0) {
                int l = pos;
                
                while (axis[pos] != pos) pos = axis[pos];
                
                res.push_back({l, pos});
            }
            
            pos++;
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
