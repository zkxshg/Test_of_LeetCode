// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
// Greedy + Sorting

class Solution {
public:
    #define ad additionalRocks
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size(), res = 0;  
        
        vector<int> div; 
        for (int i = 0; i < n; i++) {
            int d = capacity[i] - rocks[i];
            
            if (!d) res++;
            else div.push_back(d);
        }
        
        sort(div.begin(), div.end(), greater<int>());
        
        while (ad > 0 && !div.empty()) {
            if (ad >= div.back()) res++;
            ad -= div.back(); div.pop_back();
        }
        
        return res;
    }
};
