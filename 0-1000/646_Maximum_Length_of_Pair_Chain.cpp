// greedy
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = pairs.size(); if (len < 2) return len;
        
        sort(pairs.begin(), pairs.end());
        
        vector<vector<int> > pd; pd.push_back(pairs[0]);
        
        for (int i = 1; i < len; i++) {
            if (pd.back()[1] < pairs[i][0]) pd.push_back(pairs[i]);
            else if (pd.back()[1] > pairs[i][1]) pd.back()[1] = pairs[i][1];
        }
        
        return pd.size();
        
    }
};
