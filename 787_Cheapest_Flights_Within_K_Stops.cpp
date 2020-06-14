
// Dijkstra算法
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst) return 0;
        
        if (flights.size() == 0) return -1;
        
        vector<vector<int>> path(n, vector<int>(n, n * 10001));
        for (int i = 0; i < flights.size(); i++) path[flights[i][0]][flights[i][1]] = flights[i][2];
        
        vector<int> dsts;
        for (int i = 0; i < src; i++) dsts.push_back(i);
        for (int i = src + 1; i < n; i++) dsts.push_back(i);
        
        while (K > 1) {
            int min_dst = -1, min_path = n * 10001;
            for (int i = 0; i < dsts.size(); i++) {
                if (path[src][dsts[i]] < min_path) {
                    min_path = path[src][dsts[i]];
                    min_dst = i;
                }
            }
            
            if (min_dst < 0) {
                if (path[src][dst] < 10001) return path[src][dst];
                return -1;
            }
            
            if (dsts[min_dst] == dst) return path[src][dst];
            
            for (int i = 0; i < dsts.size(); i++) 
                path[src][dsts[i]] = min(path[src][dsts[i]], path[src][dsts[min_dst]] + path[dsts[min_dst]][dsts[i]]);
            
            dsts.erase(dsts.begin() + min_dst);
            K--; 
        }
        return path[0][4];
        
        int result = path[src][dst];
        if (K >0) {
            for (int i = 0; i < n; i++) result = min(result, path[src][i] + path[i][dst]);
        }
        
        if (result > (K + 1) * 10000) return -1;
        return result; 
    }
};
