// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/
// DFS

class Solution {
public:
    #define ll long long
    unordered_map<int, vector<int>> paths;
    unordered_map<int, int> vtd;
    ll res = 0;
    int sts = 0;

    int dfs(int city) {
        vtd[city]++;

        int inNum = 0;
        for (int nex : paths[city]) {
            if (!vtd[nex]) {
                int inRep = dfs(nex);
                inNum += inRep;
                res += ceil(double(inRep) / sts);
            }
        }

        return inNum + 1;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();

        res = 0; paths.clear(); vtd.clear(); sts = seats;

        for (int i = 0; i < n; i++) {
            int a = roads[i][0], b = roads[i][1];

            paths[a].push_back(b); paths[b].push_back(a);
        }

        int rep = dfs(0);

        return res;
    }
};
