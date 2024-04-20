// https://leetcode.com/problems/find-all-groups-of-farmland/?envType=daily-question&envId=2024-04-2
// BFS

class Solution {
public:
    #define pii pair<int, int>
    unordered_map<int, unordered_map<int, int>> visited;
    unordered_map<int, pii> LT;
    unordered_map<int, pii> RB;

    void BFS(int x, int y, vector<vector<int>>& land, int idx) {
        int m = land.size(), n = land[0].size();

        int x_en = x, y_en = y;
        while (x_en < m && land[x_en][y]) x_en++;
        while (y_en < n && land[x][y_en]) y_en++;

        for (int i = x; i < x_en; i++) {
            for (int j = y; j < y_en; j++) visited[i][j] = idx;
        }

        LT[idx] = make_pair(x, y);
        RB[idx] = make_pair(x_en - 1, y_en - 1);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();

        visited.clear(); LT.clear(); RB.clear();

        int idx = 1, i = 0;
        while (i < m) {
            int j = 0;

            while (j < n) {
                if (land[i][j]) {
                    if (visited[i][j]) {
                        j = RB[visited[i][j]].second;
                    }
                    else {
                        BFS(i, j, land, idx);
                        j = RB[visited[i][j]].second;
                        idx++;
                    }
                }
                j++;       
            }
            i++;
        }

        vector<vector<int>> res;

        for (int i = 1; i < idx; i++) res.push_back({LT[i].first, LT[i].second,
        RB[i].first, RB[i].second});
        
        return res;
    }
};
