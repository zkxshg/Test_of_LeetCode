// https://leetcode.com/problems/cheapest-flights-within-k-stops
// Dijkstra算法 / BFS
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst) return 0;
        if (flights.size() == 0) return -1;
        int kk = K;
        
        vector<vector<int>> path(n, vector<int>(n, n * 10001));
        for (int i = 0; i < flights.size(); i++) path[flights[i][0]][flights[i][1]] = flights[i][2];
        
        vector<int> dsts;
        for (int i = 0; i < src; i++) dsts.push_back(i);
        for (int i = src + 1; i < n; i++) dsts.push_back(i);
        
        while (K > 0) {
            vector<int> tempPath(n, n * 10001);
            for (int i = 0; i < n; i++) {
                if (i == src) continue;
                
                int min_path = path[src][i];
                for (int j = 0; j < n; j++){
                    if (j == src || j == i) continue;
                    min_path = min(min_path, path[src][j] + path[j][i]);
                }
                tempPath[i] = min_path;
            }
            path[src] = tempPath;
            K--; 
        }
        
        int result = path[src][dst];
        if (result > (kk + 1) * 10000) return -1;
        return result; 
    }
};
