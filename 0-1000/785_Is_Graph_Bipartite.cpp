// dfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); if (n < 2) return true;
        
        unordered_map<int, int> set;
        vector<int> cand;
        
        for (int i = 0; i < n; i++) {
            if (graph[i].empty()) set[i] = 1;
            else {
                set[i] = 1;
                for (int j : graph[i]) {
                    set[j] = -1;
                    cand.push_back(j);
                }
                break; 
            }
        }
        
        while (!cand.empty()) {
            vector<int> temC;
            
            for (int i : cand) {
                for (int j : graph[i]) {
                    if (!set[j]) {
                        set[j] = -set[i];
                        temC.push_back(j);
                    }
                    else if (set[j] == set[i]) return false;
                }
            }
            
            if (temC.empty()) {
                for (int i = 1; i < n; i++) {
                    if (!set[i]) {
                        set[i] = 1;
                        temC.push_back(i);
                        break;
                    }
                }
            }
            
            cand = temC;
        }
        
        return true;
    }
};
