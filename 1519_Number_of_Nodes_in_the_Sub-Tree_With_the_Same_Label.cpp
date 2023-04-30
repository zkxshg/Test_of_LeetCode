// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
// BFS

class Solution {
public:
    unordered_map<int, vector<int>> paths;
    unordered_map<int, int> visited;
    string lb;
    vector<int> res;

    vector<int> dfs(int root) {
        visited[root]++;

        vector<int> rv(26, 0);

        for (int nex : paths[root]) {
            if (!visited[nex]) {
                vector<int> nrv = dfs(nex);
                for (int i = 0; i < 26; i++) rv[i] += nrv[i];
            }
        } 
        
        rv[lb[root] - 'a']++;
        res[root] = rv[lb[root] - 'a'];

        return rv;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        paths.clear(); visited.clear(); lb = labels;

        for (auto& v : edges) {
            paths[v[0]].push_back(v[1]); paths[v[1]].push_back(v[0]);
        }

        res.resize(n, 0);

        vector<int> rFre = dfs(0);

        return res;
    }
};
