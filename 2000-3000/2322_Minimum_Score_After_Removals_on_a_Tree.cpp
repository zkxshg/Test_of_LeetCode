// 2322. Minimum Score After Removals on a Tree
// Link: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/
// Lang: C++
// Date: 2025-08-21 20:54:43.282 UTC

class Solution {
public:
    void dfs(int u, int xor1, int xor2, vector<bool>& vis, vector<vector<int>>& g, unordered_map<int, unordered_map<int, int>>& ed, int& res) {

        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;

                int xort = ed[v][u];
                int xor3 = xort ^ xor2;

                int maxXor = max({xor1, xort, xor3});
                int minXor = min({xor1, xort, xor3});
                res = min(res, maxXor - minXor);
                
                dfs(v, xor1, xor2, vis, g, ed, res);
            }
        }
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        vector<int> degree(n, 0);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);

            degree[e[0]]++;
            degree[e[1]]++;
        }

        int totalXOR = 0;
        for (int num : nums) totalXOR ^= num;

        unordered_map<int, unordered_map<int, int>> ed;
        queue<int> q;
        vector<int> xorVal(nums);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }
            
        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited[u] = true;

            for (int v : g[u]) {
                if (visited[v]) continue;

                ed[u][v] = xorVal[u];
                ed[v][u] = totalXOR ^ xorVal[u];

                xorVal[v] ^= xorVal[u];
                if (--degree[v] == 1) q.push(v);
            }
        }

        // cout << totalXOR << endl;
        // for (auto &e : edges) cout << ed[e[0]][e[1]] << "^" << ed[e[1]][e[0]] << "=" <<  (ed[e[0]][e[1]] ^ ed[e[1]][e[0]]) << endl;

        int res = INT_MAX;

        for (auto &e1 : edges) {
            int u1 = e1[0], v1 = e1[1];
           
            vector<bool> vis(n, false);
            vis[u1] = true; vis[v1] = true;

            int xor1 = ed[v1][u1], xor2 = ed[u1][v1];
            dfs(u1, xor1, xor2, vis, g, ed, res);

            xor1 = ed[u1][v1], xor2 = ed[v1][u1];
            dfs(v1, xor1, xor2, vis, g, ed, res);
        }

        return res;
    }
};
