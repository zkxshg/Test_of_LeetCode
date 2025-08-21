// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
// DFS

class Solution {
public:
    int num;
    unordered_map<int, vector<int>> undrt;
    unordered_map<int, unordered_map<int, int>> drt;
    unordered_map<int, int> visited;
    
    void dfs(int node) {
        visited[node]++;
        
        for (int nex : undrt[node]) {
            if (visited[nex]) continue;
            
            if (drt[node][nex]) num++;
            
            dfs(nex);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        num = 0; undrt.clear(); drt.clear(); visited.clear();
        
        for (auto& v : connections) {
            undrt[v[0]].push_back(v[1]); undrt[v[1]].push_back(v[0]);
            drt[v[0]][v[1]]++;
        }
        
        dfs(0);
        
        return num;
    }
};
