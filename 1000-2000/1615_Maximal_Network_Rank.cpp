// https://leetcode.com/problems/maximal-network-rank/
// hash table

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,  unordered_map<int, int>> path;
        unordered_map<int, int> deg;
        
        for (auto& v : roads) {
            path[v[0]][v[1]]++; path[v[1]][v[0]]++;
            deg[v[0]]++; deg[v[1]]++; 
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = deg[i] + deg[j];
                if (path[i][j]) rank--;
                
                res = max(res, rank);
            }
        }
        
        return res;
        
    }
};
