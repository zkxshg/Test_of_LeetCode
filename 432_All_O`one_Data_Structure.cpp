// https://leetcode.com/problems/all-oone-data-structure/
// hash table

class AllOne {
public:
    unordered_map<string, int> stringCount;
    unordered_map<int, set<string>> couSet;
    set<int> fres;
    
    AllOne() {
        stringCount.clear();
        couSet.clear();
        fres.clear();
    }
    
    void inc(string key) {
        int c = stringCount[key]; stringCount[key]++;
        
        if (c) couSet[c].erase(key);
        couSet[c + 1].insert(key);
        
        if (c && couSet[c].empty()) fres.erase(c);
        fres.insert(c + 1);
    }
    
    void dec(string key) {
        int c = stringCount[key]; stringCount[key]--;
        
        couSet[c].erase(key);
        if (c - 1) couSet[c - 1].insert(key);
        
        if (couSet[c].empty()) fres.erase(c);
        if (c - 1) fres.insert(c - 1);
    }
    
    string getMaxKey() {
        if (fres.empty()) return "";
        
        int f = *fres.rbegin();
        return *couSet[f].begin();
    }
    
    string getMinKey() {
        if (fres.empty()) return "";
        
        int f = *fres.begin();
        return *couSet[f].begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
