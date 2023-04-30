// https://leetcode.com/problems/reduce-array-size-to-the-half/
// hash table + greedy

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> fre;
        for (int i : arr) fre[i]++;
        
        vector<int> fres;
        for (auto& f : fre) fres.push_back(f.second);
        sort(fres.begin(), fres.end());
        
        int res = 0, tem = n;
        while (tem > n/2) {
            tem -= fres.back();
            res++;
            fres.pop_back();
        }
        
        return res;
    }
};
