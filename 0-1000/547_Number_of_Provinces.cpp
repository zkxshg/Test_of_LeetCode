// https://leetcode.com/problems/number-of-provinces/
// Union Find

class Solution {
public:
    #define M isConnected
    
    unordered_map<int, int> p;

    int find(int a) {
        if (p[a] == a) return a;
        return find(p[a]);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = M.size(); if (n == 1) return 1;
        
        p.clear();
        for (int i = 0; i < n; i++) p[i] = i;
        
        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) 
                if (M[i][j])
                    p[find(j)] = p[find(i)];
        
        int res = 0;
        for (int i = 0; i < n; i++)
            if (find(i) == i)
                res++;
        
        return res;
        
    }
};
