// https://leetcode.com/problems/possible-bipartition/
// BFS

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, int> group;
        
        unordered_map<int, vector<int>> dk;
        
        for (auto& dis : dislikes) {
            dk[dis[0]].push_back(dis[1]); dk[dis[1]].push_back(dis[0]);
        }
        
        vector<int> bfs_a, bfs_b; 
        group[1] = 1; bfs_a.push_back(1);
        
        int num = 1;
        while (!bfs_a.empty() || !bfs_b.empty()) {
            vector<int> tem_a, tem_b;
            
            for (int a : bfs_a) {
                for (int b : dk[a]) {
                    if (!group[b]) {
                        group[b] = 2; tem_b.push_back(b); num++;
                    }
                    else if (group[b] == 1) return false;
                }
            }
            
            for (int b : bfs_b) {
                for (int a : dk[b]) {
                    if (!group[a]) {
                        group[a] = 1; tem_a.push_back(a); num++;
                    }
                    else if (group[a] == 2) return false;
                }
            }
            
            bfs_a = tem_a; bfs_b = tem_b;
            
            if (bfs_a.empty() && bfs_b.empty() && num < n) {
                for (int i = 1; i <= n; i++) {
                    if (!group[i]) {
                        bfs_a.push_back(i); group[i] = 1; num++;
                        break;
                    }
                }
            }
        }
        
        return true;
        
    }
};
