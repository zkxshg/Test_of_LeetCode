// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Graph + Shortest Path (Floyd Algo)

class Solution {
public:
    vector<vector<int>> dis;
    
    void print2D(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
              cout << M[i][j]; if (j < n - 1) cout << ",";
            }
            cout << endl;
        }
    }

    void floyd(int n) {
        for (int k = 0; k < n; k++) 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }      
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        dis.resize(n, vector<int>(n, 0x3f3f3f3f));
        
        for (int i = 0; i < n; i++) dis[i][i] = 0;
        
        for (auto& v : edges) 
            dis[v[0]][v[1]] = dis[v[1]][v[0]] = v[2];
        
        floyd(n);
        // print2D(dis);
        
        int num = n, res = 0;
        for (int i = 0; i < n; i++) {
            int reach = 0;
            
            for (int j = 0; j < n; j++)
                if (dis[i][j] <= distanceThreshold) reach++;
            
            if (reach <= num) {
                num = reach; res = i;
            }
        }
        
        return res;
    }
};
