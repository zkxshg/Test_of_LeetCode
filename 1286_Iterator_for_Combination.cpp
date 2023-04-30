// https://leetcode.com/problems/iterator-for-combination/
// bit masking
class CombinationIterator {
public:
    vector<string> allComb;
    int pos = 0;
    
    vector<string> generAll(string characters, int combinationLength) {
        int len = characters.size();
        int maskLen = 1<<len;
        vector<string> result;
        
        for (int i = 0; i < maskLen; i++) {
            string str = "";
            
            bitset<32> bits(i);
            for (int j = 0; j < len; j++) {
                if (bits[j]) str += characters[j];
            }
            
            if (str.size() == combinationLength) result.push_back(str);
        }
        return result;
    }
    
    CombinationIterator(string characters, int combinationLength) {
        allComb = generAll(characters, combinationLength);
        sort(allComb.begin(), allComb.end());
        pos = 0;
    }
    
    string next() {
        if (pos < allComb.size()) return allComb[pos++];
        return "";
    }
    
    bool hasNext() {
        if (pos < allComb.size()) return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
