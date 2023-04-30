// https://leetcode.com/problems/smallest-string-with-swaps/
// Union-Find + Sorting

class Solution {
public:
    unordered_map<int, int> U;
    
    int find(int a) {
        if (!U.count(a)) return U[a] = a;
        if (U[a] == a) return a;
        return U[a] = find(U[a]);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        U.clear();
        
        int n = s.size();
        
        for (int i = 0; i < n; i++) U[i] = i;
        
        for (auto& p : pairs) {
            int ua = find(p[0]);
            int ub = find(p[1]);
            
            if (ua != ub) U[ub] = ua;
        }
        
        unordered_map<int, vector<int>> uni;
        
        for (int i = 0; i < n; i++) uni[find(i)].push_back(i);
        
        string res = s;
        
        for (auto& G : uni) {
            vector<char> tem;
            
            vector<int>& v = G.second;
            
            for (int ind : v) tem.push_back(s[ind]);
            
            sort(tem.begin(), tem.end());
            
            int cou = 0;
            for (int ind : v) res[ind] = tem[cou++];
        }
        
        return res;
    }
};
