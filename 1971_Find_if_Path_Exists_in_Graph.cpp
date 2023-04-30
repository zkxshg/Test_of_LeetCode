// https://leetcode.com/problems/find-if-path-exists-in-graph/
// BFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        
        unordered_map<int, vector<int>> path;
        for (auto& E : edges) {
            path[E[0]].push_back(E[1]); path[E[1]].push_back(E[0]);
        }
            
        unordered_map<int, int> visited; visited[source]++;
        vector<int> bfs; bfs.push_back(source);
        
        while (!bfs.empty()) {
            vector<int> tem;
            
            for (int pre : bfs) {
                for (int nex : path[pre]) {
                    if (!visited[nex]) {
                        if (nex == destination) return true;
                        
                        visited[nex]++;
                        tem.push_back(nex);
                    }
                }
            }
            
            bfs = tem;
        }
        
        return false;
    }
};
