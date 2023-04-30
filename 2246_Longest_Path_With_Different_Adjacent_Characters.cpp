// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/
// DFS

class Solution {
public:
    #define pii pair<int, int>

    unordered_map<int, vector<int>> egs;
    unordered_map<int, int> visited;

    string str;

    pii dfs(int root) {
        visited[root]++;

        int chiLong_1 = -1, chiLong_2 = -1, gloLong = 1;

        for (auto& nex : egs[root]) {
            if (visited[nex]) continue;
            pii chip = dfs(nex);
            
            int localNex = chip.first, globalNex = chip.second;
            gloLong = max(gloLong, globalNex);

            if (str[root] == str[nex]) continue;

            if (localNex > chiLong_1) {
                chiLong_2 = chiLong_1;
                chiLong_1 = localNex;
            }
            else if (localNex > chiLong_2) chiLong_2 = localNex;
        } 
        int localLong = 1;
        if (chiLong_1 > 0 || chiLong_2 > 0) localLong = max(chiLong_1, chiLong_2) + 1;

        if (chiLong_1 > 0 && chiLong_2 > 0) gloLong = max(gloLong, chiLong_1 + chiLong_2 + 1);
        gloLong = max(gloLong, localLong);

        // cout << root << ": " << localLong << "," << gloLong << endl;

        pii res = {localLong, gloLong};
        return res;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();

        egs.clear(); visited.clear(); str = s;

        for (int i = 0; i < n; i++) {
            if (parent[i] < 0) continue;

            egs[i].push_back(parent[i]);
            egs[parent[i]].push_back(i);
        }

        pii res = dfs(0);
        return res.second;
    }
};
