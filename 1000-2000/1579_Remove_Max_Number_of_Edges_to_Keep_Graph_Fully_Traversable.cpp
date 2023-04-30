// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/
// Union-and-Find

class Solution {
public:

    vector<int> U;

    int find(int x) {
        if (U[x] != x)
            U[x] = find(U[x]);

        return U[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            U[rootY] = rootX;
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        U.resize(2 * n + 1);

        for (int i = 1; i <= 2 * n; i++)
            U[i] = i;

        int extraEdges = 0;

        for (auto& edge : edges) {
            if (edge[0] == 3) {
                if (find(edge[1]) != find(edge[2])) {
                    unite(edge[1], edge[2]);
                    unite(edge[1] + n, edge[2] + n);
                }
                else extraEdges++;
            }
        }

        for (auto& edge : edges) {
            if (edge[0] == 1) {
                if (find(edge[1]) != find(edge[2])) unite(edge[1], edge[2]);
                else extraEdges++;
            } else if (edge[0] == 2) {
                if (find(edge[1] + n) != find(edge[2] + n)) unite(edge[1] + n, edge[2] + n);
                else extraEdges++;
            }
        }

        int countAlice = 0, countBob = 0;
        for (int i = 1; i <= n; i++) {
            if (find(i) == i) countAlice++;
            if (find(i + n) == i + n) countBob++;
        }

        if (countAlice > 1 || countBob > 1)
            return -1;

        return extraEdges;
    }
};
