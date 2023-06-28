// https://leetcode.com/problems/path-with-maximum-probability/description/
// Dijkstra

class Solution {
public:
    using pdi = pair<double, int>; // Corrected here

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int m = edges.size();

        vector<vector<pair<int, double>>> paths(n);
        for (int i = 0; i < m; i++) {
            int a = edges[i][0], b = edges[i][1];
            double prob = succProb[i];

            paths[a].push_back({b, prob});
            paths[b].push_back({a, prob});
        }

        vector<double> dist(n, 0);
        dist[start] = 1;

        priority_queue<pdi, vector<pdi>, less<pdi>> pq; // Corrected here
        pq.push({1.0, start});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end) return prob;

            if (dist[node] > prob) continue;

            for (auto &[neighbor, edgeProb] : paths[node]) {
                double newProb = prob * edgeProb;

                if (newProb > dist[neighbor]) {
                    dist[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        return 0;
    }
};
