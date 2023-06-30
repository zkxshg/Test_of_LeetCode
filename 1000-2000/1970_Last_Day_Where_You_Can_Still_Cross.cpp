// https://leetcode.com/problems/last-day-where-you-can-still-cross/description/
// Union-Find

class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, string> colMask;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootY] = rootX;

            for (int i = 0; i < colMask[rootX].size(); i++) {
                colMask[rootX][i] |= colMask[rootY][i];
            }
        }
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        const int N = row * col;

        parent.clear(); colMask.clear();

        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        string full(col, '1');

        
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
            colMask[i] = string(col, '0');
        }

        vector<vector<int>> grid(row, vector<int>(col, 0));

        set<int> topWaterLands;
        for (int day = 0; day < cells.size(); ++day) {
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            grid[r][c] = 1;

            int idx = r * col + c;
            colMask[idx][c] = 1;

            for (int i = 0; i < 8; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc]) {
                    int nidx = nr * col + nc;

                    if (find(idx) != find(nidx)) {
                        unite(idx, nidx);

                        if (colMask[idx] == full) return day;
                    }
                }
            }
        }

        return -1;
    }
};
