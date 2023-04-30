// https://leetcode.com/problems/find-original-array-from-doubled-array/
// Greedy + Hash table

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        
        sort(changed.begin(), changed.end());
        
        vector<int> org;
        
        unordered_map<int, int> dict;
        for (int i : changed) dict[i]++;
        
        for (int i = 0; i < n; i++) {
            int num = changed[i];
            
            if (!dict[num]) continue;
            else dict[num]--;
            
            if (!dict[num * 2]) return {};
            else dict[num * 2]--;
            
            org.push_back(num);
        }
        
        return org;
    }
};
