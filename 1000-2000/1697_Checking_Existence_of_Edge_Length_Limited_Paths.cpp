// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/
// Union-Find
class Solution {
public:
    #define EL edgeList
    #define Q queries

    vector<int> U;
    vector<int> rank;
    vector<int> W;

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    int find(int x, int limit) {
        while (x != U[x]) {
            if (W[x] >= limit) {
                break;
            }
            x = U[x];
        }
        return x;
    }

    void unionByRank(int x, int y, int limit) {
        int x_ref = find(x, INT_MAX);
        int y_ref = find(y, INT_MAX);

        if (x_ref != y_ref) {
            if (rank[x_ref] < rank[y_ref]) {
                U[x_ref] = y_ref;
                W[x_ref] = limit;
            } else {
                U[y_ref] = x_ref;
                W[y_ref] = limit;

                if (rank[x_ref] == rank[y_ref]) rank[x_ref]++;
            }
        }
    }

    bool withLimit(int p, int q, int limit) {
        return find(p, limit) == find(q, limit);
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        U.resize(n); rank.resize(n); W.resize(n);

        for (int i = 0; i < n; i++) U[i] = i;

        sort(EL.begin(), EL.end(), cmp);

        for (vector<int>& edge : EL) 
            unionByRank(edge[0], edge[1], edge[2]);

        vector<bool> res;
        for (vector<int>& query : Q)
            res.push_back(withLimit(query[0], query[1], query[2]));

        return res;
    }  
};

// BFS
class Solution {
public:
    #define EL edgeList
    #define Q queries

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] > b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int ub = 1000000000;
        int l1 = EL.size(), l2 = Q.size();

        vector<vector<int> > bfs(n, vector<int>(n, ub + 1));
        for (int i = 0; i < n; i++) bfs[i][i] = 0;

        sort(EL.begin(), EL.end(), cmp);
        // for (auto& v : EL) cout << v[0] << "," << v[1] << "," << v[2] << endl; 

        while (!EL.empty()) {
            vector<int> nex = EL.back();
            EL.pop_back();

            int p1 = nex[0], p2 = nex[1], dist = nex[2];

            if (bfs[p1][p2] <= ub || bfs[p2][p1] <= ub) continue;

            bfs[p1][p2] = dist;
            bfs[p2][p1] = dist;

            for (int i = 0; i < n; i++) {
                if (i == p1 || i == p2) continue;

                if (bfs[i][p1] <= ub && bfs[i][p2] > ub) {
                    bfs[i][p2] = min(bfs[i][p2], max(bfs[i][p1], dist));
                    bfs[p2][i] = bfs[i][p2];
                }

                if (bfs[i][p2] <= ub && bfs[i][p1] > ub) {
                    bfs[i][p1] = min(bfs[i][p1], max(bfs[i][p2], dist));
                    bfs[p1][i] = bfs[i][p1];
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) cout << bfs[i][j] << ",";
        //     cout << endl;
        // }

        vector<bool> res(l2);
        for (int i = 0; i < l2; i++) {
            int p1 = Q[i][0], p2 = Q[i][1], p3 = Q[i][2];

            if (bfs[p1][p2] < p3 || bfs[p2][p1] < p3) res[i] = true;
            else res[i] = false;
        }
        return res;
    }
};
