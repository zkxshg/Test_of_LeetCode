// https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/
// hash map + design

class RandomizedSet {
public:
    
    unordered_map<int, int> set;
    vector<int> hist;
    
    RandomizedSet() {
        set.clear();
        hist.clear();
    }
    
    bool insert(int val) {
        if (set[val]) return false;
        
        hist.push_back(val);
        set[val] = hist.size();
        return true;
    }
    
    bool remove(int val) {
        if (!set[val]) return false;
        
        int ind = set[val] - 1;
        
        if (ind != hist.size() - 1) {
            hist[ind] = hist.back();
            set[hist.back()] = ind + 1;
        }
        
        hist.pop_back();
        set[val] = 0;
        
        return true;
    }
    
    int getRandom() {
        return hist[rand() % hist.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
