// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
// Topological Sort 

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), m = edges.size();

        // Paths
        unordered_map<int, int> inDeg;
        unordered_map<int, set<int>> sucs;
        for (int i = 0; i < m; i++) {
            int pre = edges[i][0], suc = edges[i][1];
            sucs[pre].insert(suc);
            inDeg[suc]++;
        }
        
        // Topological Sort
        // Initial
        unordered_map<int, vector<int>> pathColor;

        vector<int> S; set<int> cyc;
        for (int i = 0; i < n; i++) {
            if (!inDeg[i]) {
                S.push_back(i);

                vector<int> pc(26);
                pc[colors[i] - 'a']++;
                pathColor[i] = pc;
            }
            else cyc.insert(i);
        }

        // Find cycle
        while (!S.empty()) {
            int rm = S.back(); S.pop_back();

            for (int nex : sucs[rm]) {
                inDeg[nex]--;

                if (pathColor.find(nex) == pathColor.end()) {
                    pathColor[nex] = pathColor[rm];
                    pathColor[nex][colors[nex] - 'a']++;
                }
                else {
                    vector<int> alter = pathColor[rm];
                    alter[colors[nex] - 'a']++;

                    for (int i = 0; i < 26; i++) 
                        pathColor[nex][i] = max(pathColor[nex][i], alter[i]);
                }

                if (inDeg[nex] <= 0) {
                    cyc.erase(nex); S.push_back(nex);
                }

            }
        }

        if (!cyc.empty()) return -1;

        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 26; j++)
                res = max(res, pathColor[i][j]);
        
        return res;
    }
};
