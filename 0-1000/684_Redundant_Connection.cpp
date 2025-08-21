// https://leetcode.com/problems/redundant-connection/
// graph + dfs

class Solution {
public:
    vector<int> id;
    vector<int> low;
    unordered_map<int, vector<int> > E;
    // vector<vector<int>> res;
    int index;
    
    void dfs(int tem, int pre) {
        id[tem] = index; low[tem] = index; index++;

        for (int next : E[tem]) {
            if (!id[next]) {
                dfs(next, tem);
                low[tem] = min(low[tem], low[next]);
            }
            else if (next != pre)
                low[tem] = min(low[tem], low[next]);

            // if (low[next] < id[tem]) res.push_back({ tem, next });
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        id  = vector<int>(n + 1);
        low = vector<int>(n + 1);
        
        index = 1;

        E.clear();
        for (vector<int> v : edges) {
            E[v[0]].push_back(v[1]);
            E[v[1]].push_back(v[0]);
        }
        
        // res.clear();
        
        for (int i = 1; i <= n; i++) 
            if (!id[i])
                dfs(i, i);
        
       // for (int i = 1; i <= n; i++) cout << id[i] << ": " << low[i] << ","; cout << endl;
        for (int i = n - 1; i >= 0; i--) {
            int x = edges[i][0], y = edges[i][1];
            if (low[x] != id[x] || low[y] != id[y]) 
                if (low[x] == low[y])
                    return edges[i];
        }
            
        
        return edges[0];
    }
};
