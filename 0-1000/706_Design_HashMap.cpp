// https://leetcode.com/problems/design-hashmap/
// design + hash map
class MyHashMap {
public:
    vector<int> hashK;
    vector<int> hashV;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        hashK.clear(); hashK.resize(22000, -1);
        hashV.clear(); hashV.resize(22000, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hk = modhash(key);
        hashK[hk] = key;
        hashV[hk] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hk = modhash(key);
        return hashV[hk];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hk = modhash(key);
        hashV[hk] = -1;
    }
    
    int modhash(int a) {
        int hk = (a % 100) + (a / 100);
        while (hashK[hk] > 0 && hashK[hk] != a) hk = (hk + 1) % 22000; 
        return hk;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
