// https://leetcode.com/problems/sort-the-people/
// sorting

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        
        vector<pair<int, int> > H;
        for (int i = 0; i < n; i++) H.push_back({heights[i], i});
        sort(H.begin(), H.end());
        
        vector<string> res;
        while (!H.empty()) {res.push_back(names[H.back().second]); H.pop_back();}
        return res;
    }
};
