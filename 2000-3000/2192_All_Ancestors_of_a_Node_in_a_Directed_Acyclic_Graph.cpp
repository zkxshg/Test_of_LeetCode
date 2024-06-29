// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/?envType=daily-question&envId=2024-06-29
// Graph + topological sort

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> ancestors(n);
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        
        // Build adjacency list and calculate indegrees
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1];
            adj[from].push_back(to);
            indegree[to]++;
        }
        
        // Topological sorting
        queue<int> zero_indegree;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                zero_indegree.push(i);
            }
        }
        
        while (!zero_indegree.empty()) {
            int node = zero_indegree.front();
            zero_indegree.pop();
            
            for (int neighbor : adj[node]) {
                // Add all ancestors of node to adjacency node
                for (int ancestor : ancestors[node]) {
                    ancestors[neighbor].insert(ancestor);
                }
                
                ancestors[neighbor].insert(node);
                
                if (--indegree[neighbor] == 0) {
                    zero_indegree.push(neighbor);
                }
            }
        }
        
        // Convert vector of sets to vector of vectors (sorted)
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }
        
        return result;
    }
};
