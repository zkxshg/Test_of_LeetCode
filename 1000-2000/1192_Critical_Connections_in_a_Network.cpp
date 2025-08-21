// https://leetcode.com/problems/critical-connections-in-a-network/
// DFS - Tarjan's algorithm
class Solution {
public:
    vector<int> id;
    vector<int> low;
    unordered_map<int, vector<int> > edges;
    vector<vector<int>> res;
    int index;
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        id = vector<int>(n);
        low = vector<int>(n);
        
        index = 1;
        
        edges.clear();
        for (vector<int> v : connections) {
            edges[v[0]].push_back(v[1]);
            edges[v[1]].push_back(v[0]);
        }
        
        res.clear();
        
        for (int i = 0; i < n; i++)
            if (!id[i])
                dfs(i, i);
        
        return res;
    }
    
    void dfs(int tem, int pre) {
        id[tem] = index; low[tem] = index; index++;
        
        for (int next : edges[tem]) {
            if (!id[next]) {
                dfs(next, tem);
                low[tem] = min(low[tem], low[next]);
            }
            else if (next != pre)
                low[tem] = min(low[tem], low[next]);
            
            if (low[next] > id[tem]) res.push_back({tem, next}); 
        }
    }
};
