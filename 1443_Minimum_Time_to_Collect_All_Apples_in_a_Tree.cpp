// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
// Tree + DFS

class Solution {
public:
    unordered_map<int, vector<int>> egs;
    unordered_map<int, int> visited;

    int dfs(int root, vector<bool>& HA) {
        visited[root]++;

        int cost = 0;
        for (int nex : egs[root]) {
            if (!visited[nex]) cost += dfs(nex, HA);
        }

        if (HA[root] || cost) cost += 2;

        return cost;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        egs.clear(); visited.clear();
        for (auto& v : edges) {
            egs[v[0]].push_back(v[1]);
            egs[v[1]].push_back(v[0]);
        }

        int res = dfs(0, hasApple);

        if (res > 0) return res - 2;
        
        return res;
    }
};
