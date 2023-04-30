// https://leetcode.com/problems/all-paths-from-source-to-target/
// BFS

class Solution {
public:
    #define G graph
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = G.size(); if (G[0].empty()) return {};
        
        vector<vector<int> > res;
        
        vector<vector<int> > bfs;
        for (int i : G[0]) {
            if (i == n - 1) res.push_back({0, n - 1});
            else bfs.push_back({0, i});     
        }
        
        while (!bfs.empty()) {
            vector<vector<int> > tem;
            
            for (auto& v : bfs) {
                int tail = v.back();
                
                for (int i : G[tail]) {
                    vector<int> nvec = v; 
                    nvec.push_back(i);
                    
                    if (i == n - 1) res.push_back(nvec);
                    else tem.push_back(nvec);     
                }
            }
            
            bfs = tem;
        }
        
        return res;
    }
};
