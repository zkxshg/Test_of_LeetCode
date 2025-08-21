// https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
// Graph + MST(Kruskal) + Sorting

class Solution {
public:
    int V;
    
    vector<int> par;
    
    vector<vector<int> > lastPath;
    
    int find(int x) {
        return (x == par[x])? x : find(par[x]);
    }
    
    void merge(int x, int y) {
        par[find(x)] = find(y);
    }
    
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    
    void initialP() {
        par.resize(0); par.resize(V);
        for (int i = 0; i < V; i++) par[i] = i;
    }
    
    int kruskal(int n, int E, vector<vector<int>>& edges, int cost) {
        sort(edges.begin(), edges.begin() + E, cmp);

        for (int i = 0, j = 0; i < n - 1 && j < E; i++) {
            // Check circle
            while (j < E && find(edges[j][0]) == find(edges[j][1])) j++;
            if (j >= E) break;
            
            // add the edge[j]
            merge(edges[j][0], edges[j][1]);
            cost += edges[j][2];
            
            lastPath.push_back(edges[j]);
            
            j++;
        }

        // cout << "MST = " << cost << endl;
        return cost;
    }
    
    void print2D(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
              cout << M[i][j]; if (j < n - 1) cout << ",";
            }
            cout << endl;
        }
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        V = n;
        
        int E = edges.size();
        // sort(edges.begin(), edges.end(), cmp);
        vector<vector<int> > defEdges = edges;
        
        // First MST
        initialP(); lastPath.clear();
        int c = kruskal(n, E, edges, 0);
        
        // Rec the full MST path
        vector<vector<int>> fullPath = lastPath;
        // print2D(fullPath);
        
        vector<int> critical; vector<int> pse_cri;
        for (int i = 0; i < E; i++) {
            vector<int> v = defEdges[i];
            // print2D(edges);
            
            initialP(); lastPath.clear();

            if (std::find(fullPath.begin(), fullPath.end(), v) != fullPath.end()) { 
                // If v in full MST path
                
                remove(edges.begin(), edges.end(), v); // remove v from paths
     
                int mst = kruskal(n, E - 1, edges, 0); // re-gener MST
                
                if (lastPath.size() < n - 1) mst = 100001;
                
                if (mst <= c) pse_cri.push_back(i); // cost increase
                else critical.push_back(i); // cost not increase
                
                edges[E - 1] = v; // add v back
            }
            else {
                // If v not in full MST path
                lastPath.push_back(v);
                
                merge(v[0], v[1]); // Set v as connected
                
                int mst = kruskal(n - 1, E, edges, v[2]);
                
                if (lastPath.size() < n - 1) mst = 100001;
                
                if (mst <= c) pse_cri.push_back(i);
            }
        }
        
        return {critical, pse_cri};
    }
};
