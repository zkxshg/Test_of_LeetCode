// https://leetcode.com/problems/snapshot-array/
// Design + Binary Search

class SnapshotArray {
public:
    unordered_map<int, vector<pair<int, int>> > snapArr;
    int id;
    
    SnapshotArray(int length) {
        snapArr.clear(); id = 0;
    }
    
    void set(int index, int val) {
        auto& parr = snapArr[index];
        
        if (!parr.empty() && parr.back().first == id) parr.back().second = val;
        else snapArr[index].push_back(make_pair(id, val));
    }
    
    int snap() {
        id++;
        return id - 1;
    }
    
    
    int get(int index, int snap_id) {
        auto& parr = snapArr[index];
        
        if (parr.empty()) return 0;
        
        int n = parr.size();
        
        int st = 0, en = n - 1;
        while (st < en) {
            int mid = (st + en) / 2;
            
            if (parr[mid].first == snap_id) return parr[mid].second;
            if (mid > 0 && parr[mid - 1].first < snap_id && parr[mid].first > snap_id)
                return parr[mid - 1].second;
            if (mid < n - 1 && parr[mid + 1].first > snap_id && parr[mid].first < snap_id)
                return parr[mid].second;
            else if (parr[mid].first > snap_id) en = mid;
            else st = mid + 1;
            // cout << mid << " = " << parr[mid].first << "<-" << st << "," << en << endl;
        }
        
        if (parr[st].first == snap_id) return parr[st].second;
        if (parr[st].first > snap_id) return 0;
        if (parr[st].first < snap_id) return parr.back().second;

        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
