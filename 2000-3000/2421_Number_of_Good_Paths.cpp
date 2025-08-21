// https://leetcode.com/problems/number-of-good-paths/description/
// Union Find

class Solution {
public:
    #define pii pair<int, int>

    unordered_map<int, int> U;

    int find(int a) {
        if(U[a] < 0) return -1;
        if (U[a] == a) return a;
        return find(U[a]);
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        U.clear(); 
        for (int i = 0; i < n; i++) U[i] = -1;

        unordered_map<int, vector<int>> egs;
        for (auto& v :edges) {
            egs[v[0]].push_back(v[1]);
            egs[v[1]].push_back(v[0]);
        }

        int res = 0;

        vector<pii> sp;
        for (int i = 0; i < n; i++) sp.push_back({vals[i], i});
        sort(sp.begin(), sp.end());

        unordered_map<int, int> cnts;
        unordered_map<int, int> cntNum;
        for (int i = 0; i < n; i++) {
            int vi = sp[i].first, pi = sp[i].second;

            cnts[pi]++; cntNum[pi] = vi;
            res++;

            // Union
            U[pi] = pi;
            for (int nex : egs[pi]) {
                if (U[nex] >= 0) {
                    int ua = find(pi), ub = find(nex);

                    if (cntNum[ub] != vi) {
                        cntNum[ub] = vi; cnts[ub] = 0; 
                    }

                    if (ua != ub) {
                        res += cnts[ub] * cnts[ua];
                        cnts[ub] += cnts[ua];

                        U[ua] = U[ub];
                    }
                }
            }
            // for (int i = 0; i < n; i++) cout << find(i) << ","; cout << endl;
        }
        
        return res;
    }
}; 
