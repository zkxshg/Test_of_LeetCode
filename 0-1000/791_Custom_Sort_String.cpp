// https://leetcode.com/problems/custom-sort-string/
// hash table + sorting

class Solution {
public:
    string customSortString(string order, string str) {
        int n = order.size(), m = str.size();
        
        unordered_map<char, int> rank;
        for (int i = 0; i < n; i++) rank[order[i]] = i + 1;
                                         
        vector<pair<int, char> > sp;
        for (char c : str) sp.push_back(make_pair(rank[c], c));
        sort(sp.begin(), sp.end());
        
        string res = "";
        for (auto& p : sp) res += p.second;
        
        return res;
    }
};
