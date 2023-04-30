// https://leetcode.com/problems/network-delay-time/
// Dijsktra

class Solution {
public:
    
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }    
    };
    
    vector<int> Dijkstra(vector<vector<int>>& edges, int n, int k) {
        vector<int> dist(n, INT_MAX); dist[k - 1] = 0;
        
        // save paths
        unordered_map<int, unordered_map<int, int>> path;
        for (auto& e : edges) path[e[0] - 1][e[1] - 1] = e[2];
        
        // queue to keep dist
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> nodes;
        nodes.push({k - 1, 0});

        while (!nodes.empty()) {
            int N = nodes.top().first; nodes.pop();

            for (auto& p : path[N]) {
                int v = p.first, d = p.second;

                if (dist[N] + d < dist[v]) {
                    dist[v] = dist[N] + d;
                    nodes.push(make_pair(v, dist[v]));
                }
            }
        }
        
        return dist;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist = Dijkstra(times, n, k);
        
        int maxDist = -1;
        for (int i : dist) {
            if (i == INT_MAX) return -1;
            maxDist = max(maxDist, i);
        }
        
        return maxDist;
    }
};
