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

// https://leetcode.com/problems/regions-cut-by-slashes/solutions/5614698/beats-100-explained-with-video-c-java-python-js-union-find-explained-in-detail/
class Solution {
    vector<int> parent;
    vector<int> rank;
    int count;
    
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dots = n + 1;
        parent.resize(dots * dots);
        rank.resize(dots * dots, 1);
        count = 0;

        // Initialize Union-Find structure
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }

        // Connect boundaries to the top-left corner (0,0)
        for (int i = 0; i < dots; ++i) {
            for (int j = 0; j < dots; ++j) {
                if (i == 0 || j == 0 || i == n || j == n) {
                    int cell = i * dots + j;
                    unionSets(0, cell);
                }
            }
        }

        // Process each cell and connect regions based on slashes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    int cell1 = i * dots + j;
                    int cell2 = (i + 1) * dots + (j + 1);
                    unionSets(cell1, cell2);
                } else if (grid[i][j] == '/') {
                    int cell1 = (i + 1) * dots + j;
                    int cell2 = i * dots + (j + 1);
                    unionSets(cell1, cell2);
                }
            }
        }

        return count;
    }
    
private:
    void unionSets(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);
        if (parentA == parentB) {
            count++;
        } else {
            if (rank[parentA] > rank[parentB]) {
                parent[parentB] = parentA;
            } else if (rank[parentA] < rank[parentB]) {
                parent[parentA] = parentB;
            } else {
                parent[parentB] = parentA;
                rank[parentA]++;
            }
        }
    }
    
    int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }
};
