// https://leetcode.com/problems/check-if-n-and-its-double-exist/ 
// hash map
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> dict;
        for (int i : arr) dict[i]++;
        if (dict[0] > 1) return true;
        for (int i : arr) {
            if (!i) continue;
            else {
                if (dict[i * 2]) return true;
                else if (!(i&1) &&  dict[i / 2]) return true;
            }
        }
        return false;
    }
};
