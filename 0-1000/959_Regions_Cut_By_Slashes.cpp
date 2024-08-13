// https://leetcode.com/problems/regions-cut-by-slashes/?envType=daily-question&envId=2024-08-10
// Union Find + Matrix

class Solution {
public:
    unordered_map<int, int> U;

    int find(int a) {
        if (!U.count(a)) return U[a] = a;
        if (U[a] == a) return a;
        return U[a] = find(U[a]);
    }

    int id(int x, int y, int n) {
        return x * n + y;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int len = n * n * 4;

        U.clear();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int eid = id(i, j, n);
                int a = 4 * eid, b = 4 * eid + 1, c = 4 * eid + 2, d = 4 * eid + 3;
                int ua = find(a), ub = find(b), uc = find(c), ud = find(d);

                if (grid[i][j] == '/') {
                    if (ua != ud) U[ud] = ua;
                    if (ub != uc) U[uc] = ub;
                }
                else if (grid[i][j] == '\\') {
                    if (ua != ub) U[ub] = ua;
                    if (ud != uc) U[uc] = ud;
                }
                else {
                    if (ua != ub) U[ub] = ua;
                    if (ua != uc) U[uc] = ua;
                    if (ua != ud) U[ud] = ua;
                }

                if (i < n - 1) {
                    int nex_d = 4 * id(i + 1, j , n) + 3;
                    U[nex_d] = ub;
                }

                if (j < n - 1) {
                    int nex_a = 4 * id(i, j + 1, n);
                    U[nex_a] = uc;
                }
            }
        }

        unordered_map<int, int> visited;
        int cou = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int eid = id(i, j, n);
                int a = 4 * eid, b = 4 * eid + 1, c = 4 * eid + 2, d = 4 * eid + 3;
                int ua = find(a), ub = find(b), uc = find(c), ud = find(d);

                if (!visited[ua]) {visited[ua]++; cou++;} 
                if (!visited[ub]) {visited[ub]++; cou++;} 
                if (!visited[uc]) {visited[uc]++; cou++;} 
                if (!visited[ud]) {visited[ud]++; cou++;} 
            }
        }

        return cou;
        
    }
};
