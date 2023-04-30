// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
// Union Find

class Solution {
public:
    unordered_map<int, int> U;

    int find(int a) {
        int ua = U[a];

        if (ua == a) return a;

        int pa = find(ua);
        U[a] = pa;

        return pa;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        U.clear();
        for (int i = 0; i <= n; i++) U[i] = i; 

        for (auto& v : roads) {
            int a = v[0], b = v[1];

            int pa = find(a), pb = find(b);
            U[pb] = pa;
        }
        
        int res = 10001, u1 = find(1);
        for (auto& v : roads) {
            if (find(v[0]) == u1) res = min(res, v[2]);
        }
        return res;
    }
};
