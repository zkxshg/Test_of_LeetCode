// https://leetcode.com/problems/lru-cache/
// design
class LRUCache {
public:
    unordered_map<int, int> cacheM;
    vector<int> order;
    int maxCap;
    
    LRUCache(int capacity) {
        maxCap = capacity;
        cacheM.clear();
        order.clear();
    }
    
    int get(int key) {
        if (order.size() == 0) return -1;
        else if (cacheM[key]) {
            auto it = find(order.begin(), order.end(), key);
            order.erase(it);
            order.push_back(key);
            return cacheM[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (cacheM[key] && cacheM[key] > -1) {
            cacheM[key] = value;  
            auto it = find(order.begin(), order.end(), key);
            order.erase(it);
            order.push_back(key);
        }
        else if (order.size() < maxCap) {
            cacheM[key] = value;
            order.push_back(key);
        }
        else {
            int delK = order.front();
            cacheM.erase(delK);
            order.erase(order.begin());
            cacheM[key] = value;
            order.push_back(key);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
