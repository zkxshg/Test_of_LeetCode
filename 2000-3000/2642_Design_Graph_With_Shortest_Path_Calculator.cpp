// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/
// Graph + Dijsktra

class Graph {
public:
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }    
    };

    vector<vector<int> > dist;

    Graph(int n, vector<vector<int>>& edges) {
        dist.resize(n, vector<int>(n, INT_MAX));

        for(auto& v : edges) dist[v[0]][v[1]] = v[2];
    }
    
    void addEdge(vector<int> edge) {
        dist[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        int n = dist.size();

        vector<int> arr(n, INT_MAX); arr[node1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> nodes;
        nodes.push({node1, 0});

        while(!nodes.empty()) {
            int v = nodes.top().first, current_dist = nodes.top().second; 
            nodes.pop();

            int dv = arr[v];
            if (current_dist > dv) continue;

            vector<int>& nexDist = dist[v];

            for (int i = 0; i < n; i++) {
                if (nexDist[i] >= INT_MAX) continue;

                if (dv + nexDist[i] < arr[i]) {
                    arr[i] = dv + nexDist[i];
                    nodes.push({i, arr[i]});
                }
            }

        }

        if (arr[node2] >= INT_MAX) return -1;
        return arr[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
