// https://leetcode.com/problems/array-of-doubled-pairs/
// Greedy + hash map

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> fre;
        for (int i : arr) fre[i]++;
        
        sort(arr.begin(), arr.end());
        for (int i : arr) {
            if (fre[i]) {
                if (i < 0 && !(i%2) &&fre[i / 2]) {
                    fre[i]--; fre[i / 2]--;
                }
                else if (fre[i * 2]) {
                    fre[i]--; fre[i * 2]--;
                }
                else return false;
            }
        }
        
        return true;
    }
};
