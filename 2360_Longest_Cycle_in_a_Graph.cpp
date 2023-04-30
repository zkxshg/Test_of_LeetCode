// https://leetcode.com/problems/longest-cycle-in-a-graph/description/
// Topological Sort

class Solution {
public:

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        unordered_map<int, int> inDeg;
        for (int i = 0; i < n; i++) inDeg[edges[i]]++;

        vector<int> S; set<int> cyc;
        for (int i = 0; i < n; i++) {
            if (!inDeg[i]) S.push_back(i);
            else cyc.insert(i);
        }

        while (!S.empty()) {
            int rm = S.back(), aim = edges[rm];
            S.pop_back();

            if (aim >= 0) {
                inDeg[aim]--;

                if (inDeg[aim] <= 0) {
                    cyc.erase(aim); S.push_back(aim);
                }
            }
        }

        int res = -1;
        while (!cyc.empty()) {
            int tres = 1, st = *cyc.begin(), nex = edges[st];
            cyc.erase(st);

            while (nex != st) {
                tres++; cyc.erase(nex); nex = edges[nex];
            }

            res = max(res, tres);
        }

        return res;
    }
};
