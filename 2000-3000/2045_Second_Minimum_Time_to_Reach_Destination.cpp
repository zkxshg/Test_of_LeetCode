// https://leetcode.com/problems/second-minimum-time-to-reach-destination/?envType=daily-question&envId=2024-07-28
// Graph + Dijkstra + Math

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Construct adjacency list for the graph
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // Dijkstra's algorithm to find shortest paths from node 1
        vector<int> dist(n + 1, INT_MAX);
        vector<int> secondDist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[1] = 0; secondDist[1] = 2;
        pq.push({0, 1});
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d > secondDist[u]) continue;
                
            for (int v : graph[u]) {
                int new_dist = d + 1;
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    pq.push({new_dist, v});
                }
                else if (new_dist > dist[v] && new_dist < secondDist[v]) {
                    secondDist[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }

        int minEdgeNum = dist[n], secondMinEdgeNum = secondDist[n];

        // cout << minEdgeNum << ":" << secondMinEdgeNum << endl;
        if (secondMinEdgeNum >= INT_MAX || secondMinEdgeNum - minEdgeNum > 2) {
            secondMinEdgeNum = minEdgeNum + 2;
        }
        // cout << minEdgeNum << ":" << secondMinEdgeNum << endl;

        // for (int i : dist) cout << i << ",";  cout << endl;
        // for (int i : secondDist) cout << i << ","; cout << endl;
        
        // Calculate the result based on secondMinDistances[n]
        int edgeNum = secondMinEdgeNum;
        // int singleNum = ceil((double)change / time);
        // int dnum = ceil((double)edgeNum / singleNum);
        // int result = (dnum - 1) * change * 2 + (edgeNum - (dnum - 1) * singleNum) * time;
        // cout << edgeNum << ":" << singleNum << ":" << dnum << endl;

        int result = 0;
        for (int i = 0; i < edgeNum - 1; i++) {
            result += time;
            if (result % (2 * change) >= change) 
                result = (result / (2 * change)+ 1) * (2 * change);
        }
        
        return result + time;
    }
};
