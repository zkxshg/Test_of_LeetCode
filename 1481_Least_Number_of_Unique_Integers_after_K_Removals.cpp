// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
// greedy

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> dict;
        for (int i : arr) dict[i]++;
        
        vector<int> fre;
        for (auto& p : dict) fre.push_back(p.second);
        
        sort(fre.begin(), fre.end());
        
        int pos = 0;
        while (k > 0 && pos < fre.size()) {
            k -= fre[pos]; pos++;
        }
        
        int res = fre.size() - pos;
        if (k < 0) res++;
    
        return res;
    }
};
