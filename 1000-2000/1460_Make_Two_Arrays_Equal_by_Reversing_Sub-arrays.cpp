// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
// hash table

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) return false;
        
        unordered_map<int, int> fre;
        for (int i : target) fre[i]++;
        for (int a : arr) {
            if (!fre[a]) return false;
            fre[a]--;
        }
        return true;
    }
};
