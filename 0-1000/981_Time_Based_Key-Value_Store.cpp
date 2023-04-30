// https://leetcode.com/problems/time-based-key-value-store/
// Design + hash table + binary search

class TimeMap {
public:
    unordered_map<string, unordered_map<int, string>> TM;
    unordered_map<string, vector<int>> stp;
    
    TimeMap() {
        TM.clear();
        stp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        TM[key][timestamp] = value;
        stp[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        vector<int>& stamp = stp[key];
        
        int ub = upper_bound(stamp.begin(), stamp.end(), timestamp) - stamp.begin();
        
        if (ub <= 0) return "";
        return TM[key][stamp[ub - 1]];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
