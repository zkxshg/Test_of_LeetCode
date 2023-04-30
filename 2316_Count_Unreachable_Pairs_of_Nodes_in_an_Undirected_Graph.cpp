// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
// Union Find

class Solution {
public:
    #define ll long long

    unordered_map<int, int> U;

    int find(int a) {
        int ua = U[a];

        if (ua == a) return a;

        int pa = find(ua);
        U[a] = pa;

        return pa;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        U.clear();  // Initial
        unordered_map<int, int> Unum;
        for (int i = 0; i < n; i++) {
            U[i] = i; Unum[i] = 1;
        }

        
        for (auto& v : edges) {  // Union
            int a = v[0], b = v[1];

            int pa = find(a), pb = find(b);

            
            if (pa != pb) {
                U[pb] = pa; Unum[pa] += Unum[pb];
            }
        }

        set<int> unis;  // count
        
        ll res = 0; ll acc = 0;
        for (int i = 0; i < n; i++) {
            int ui = find(i);

            if (unis.count(ui)) continue;
            
            if (unis.empty()) {
                acc += Unum[ui]; unis.insert(ui);
            }
            else {
                res += acc * Unum[ui]; acc += Unum[ui]; unis.insert(ui);
            }
            // cout << i << "," << acc << " + " << Unum[ui] << "," << res << endl;
        }
        
        return res;
    }
};
