// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
// hash table

class Solution {
public:
    #define AP adjacentPairs

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = AP.size() + 1;

        unordered_map<int, vector<int>> path;
        unordered_map<int, int> deg;

        for (auto& v : AP) {
            int a = v[0], b = v[1];
            path[a].push_back(b);
            path[b].push_back(a);

            deg[a]++; deg[b]++;
        }

        unordered_map<int, int> vtd;
        vector<int> res;

        for (auto& p : deg) {
            if (p.second == 1) {
                res.push_back(p.first); vtd[p.first]++;
                break;
            }
        }

        for (int i = 1; i < n; i++) {
            int pre = res.back();
            if (path[pre].size() < 2) {
                res.push_back(path[pre][0]);
                vtd[res.back()]++;
            }
            else {
                if (vtd.find(path[pre][0]) == vtd.end()) res.push_back(path[pre][0]);
                else res.push_back(path[pre][1]);
 
                vtd[res.back()]++;
            }
        }

        return res;
    }
};
