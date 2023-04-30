// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Union-Find

class Solution {
public:
    #define cnts connections
    
    unordered_map<int, int> U;
    
    int find(int a) {
        if (!U.count(a)) return U[a] = a;
        if (U[a] == a) return a;
        return U[a] = find(U[a]);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = cnts.size();
        if (len < n - 1) return -1;
        
        U.clear();
        for (int i = 0; i < n; i++) U[i] = i;
        
        // Union-Find
        for (auto& v : cnts) {
            int pa = find(v[0]), pb = find(v[1]);
            
            if (pa != pb) U[pb] = pa;
        }
        
        unordered_map<int, int> V;
        
        int num = 0;
        for (int i = 0; i < n; i++) {
            int pi = find(i);
            if (!V[pi]) {
                V[pi]++; num++;
            }
        }
        
        return num - 1;
    }
};
