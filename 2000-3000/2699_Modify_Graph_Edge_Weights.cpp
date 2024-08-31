// https://leetcode.com/problems/modify-graph-edge-weights/?envType=daily-question&envId=2024-08-30
// Graph + Shortest Path

class Solution {
public:
    #define ll long long
    #define pii pair<int, int>
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        unordered_map<int, unordered_map<int, int>> adj; // Change to unordered_map
        vector<pii> edgeList; // List of edges with weight -1
        vector<int> edgeIndex; // To map modified edges back to the result

        unordered_map<int, unordered_map<int, int>> negDict;

        int UB = 1e7 + 1;
        
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (w != -1) {
                adj[u][v] = w;
                adj[v][u] = w;
            } else {
                edgeList.emplace_back(u, v);
                edgeIndex.push_back(i);

                negDict[u][v] = -1;
                negDict[v][u] = -1;
            }
        }
        
        // Helper function for Dijkstra's algorithm with predecessor tracking
        auto dijkstra = [&](int start, vector<int>& pred) {
            vector<ll> dist(n, INT_MAX);
            priority_queue<pii, vector<pii>, greater<>> pq;
            dist[start] = 0;
            pq.emplace(0, start);
            
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                
                for (auto [v, w] : adj[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pred[v] = u;
                        pq.emplace(dist[v], v);
                    }
                }
            }
            
            return dist;
        };
        
        vector<int> pred(n, -1);
        vector<ll> dist_pos = dijkstra(source, pred);
        
        // If initial distance is less than target, return empty
        if (dist_pos[destination] < target) {
            return {};
        }

        cout << "Initial shortest distance is " << dist_pos[destination] << endl;
        
        // Set all -1 edges to weight 1
        unordered_map<int, unordered_map<int, int>> temAdj = adj;

        for (auto [u, v] : edgeList) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
         
        vector<int> newPred(n, -1);
        vector<ll> dist_neg = dijkstra(source, newPred);
        
        // If distance with weight 1 is still less than target, adjust edge weights
        if (dist_neg[destination] > target) {
            return {};
        }

        cout << "Distance with weight 1 is " << dist_neg[destination] << endl;
        for (int i = 0; i < n; i++) cout << newPred[i] << ","; cout << endl;

        int diff = target - dist_neg[destination];

        for (auto [u, v] : edgeList) {
            adj[u][v] = 1 + target;
            adj[v][u] = 1 + target;
        }

        int tem = destination, neg_u = 0, neg_v = 1;
        while (tem != source) {
            int pre = newPred[tem];
            if (negDict[pre].count(tem)) {
                adj[pre][tem] = 1;
                adj[tem][pre] = 1;
            } 
            tem = pre;
        }

        int temDist = dist_neg[destination];
        while (temDist < target) {   
            diff = target - temDist;

            tem = destination;
            while (tem != source) {
                int pre = newPred[tem];

                if (negDict[pre].count(tem)) {
                    adj[pre][tem] = 1 + diff;
                    adj[tem][pre] = 1 + diff;
                    break;
                } 
                tem = pre;
            }

            vector<int> temPre(n, -1);
            temDist = dijkstra(source, temPre)[destination];
            newPred = temPre;
        }
        
        vector<vector<int>> result;

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (w == -1) {
                result.push_back({u, v, adj[u][v]});
            } else {
                result.push_back({u, v, w});
            }
        }
        
        return result;
    }
};
