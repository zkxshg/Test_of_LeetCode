// https://leetcode.com/problems/bus-routes/
// BFS + Hash table

class Solution {
public:
    unordered_map<int, vector<int>> b2s;
    unordered_map<int, vector<int>> s2b;
    unordered_map<int, int> buss;
    unordered_map<int, int> stops;

    int T, res;

    void bfs(int src, int num) {

        vector<int> bque;
        for (int bus : s2b[src]) {
            if (!buss[bus] || buss[bus] > num + 1) {
                buss[bus] = num + 1; bque.push_back(bus);
            }
        }

        for (int bus : bque) {
            for (int stop : b2s[bus]) {
                if (stop == T) {
                    res = min(res, num + 1);
                    return;
                }

                if (!stops[stop] || stops[stop] > num + 1){
                    stops[stop] = num + 1;
                    bfs(stop, num + 1);
                }
            }
        }
    }


    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        b2s.clear(); s2b.clear(); buss.clear(); stops.clear();

        int n =  routes.size();
        for (int i = 0; i < n; i++) {
            for (auto& stop : routes[i]) {
                b2s[i].push_back(stop);
                s2b[stop].push_back(i);
            }
        }

        if (s2b[target].empty()) return -1;

        T = target, res = 1001;

        stops[source] = 0;
        bfs(source, 0);

        if (res > 1000) return -1;
        return res;
    }
};
