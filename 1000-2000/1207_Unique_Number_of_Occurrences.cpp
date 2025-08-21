// https://leetcode.com/problems/unique-number-of-occurrences/
// hash table

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> fre;
        for (int i : arr) fre[i]++;
        
        unordered_map<int, int> frefre;
        for (auto& p : fre) {
            if (frefre[p.second]) return false;
            frefre[p.second]++;
        }
        return true;
    }
};
