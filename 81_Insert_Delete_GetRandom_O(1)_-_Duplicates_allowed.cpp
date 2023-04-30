//https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
// Design + hash table

class RandomizedCollection {
public:
    unordered_map<int, set<int>> sets;
    vector<int> hist;
    
    RandomizedCollection() {
        sets.clear();
        hist.clear();
    }
    
    bool insert(int val) {
        bool pre = false;
        if (sets[val].empty()) pre = true;
                            
        hist.push_back(val);
        sets[val].insert(hist.size());
        
        return pre;
    }
    
    bool remove(int val) {
        if (sets[val].empty()) return false;
        
        auto it = sets[val].begin();
        // advance(it, rand() % sets[val].size());
        int pos = *it;
        //for (auto i : sets[val]) cout << i << ","; cout << endl;
        
        hist[pos - 1] = hist.back();
        
        if (hist.back() != val) {
            sets[hist.back()].erase(hist.size());
            sets[hist.back()].insert(pos);
            sets[val].erase(pos);
        }
        else sets[hist.back()].erase(hist.size());
        
        hist.pop_back();
        return true;
    }
    
    int getRandom() {
        return hist[rand() % hist.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
