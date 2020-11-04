// BFS
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n < 2) return {0};
        if (n < 3) return {0, 1};
        
        vector<vector<int> > nex(n);
        vector<int> deg(n, 0);
        
        for (vector<int> pa : edges) {
            int a = pa[0], b = pa[1];
            nex[a].push_back(b); nex[b].push_back(a);
            deg[a]++; deg[b]++;
        }
        
        vector<int> path;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) path.push_back(i);
        }
        
        while (!path.empty()) {
            vector<int> temp;
            
            for (int node : path) {
                vector<int> cons = nex[node];
                for (int con : cons) {
                    deg[con]--;
                    if (deg[con] == 1) temp.push_back(con);
                }
            }
            
            if (temp.empty()) break;
            path = temp;
        }
        
        return path;
    }
};
