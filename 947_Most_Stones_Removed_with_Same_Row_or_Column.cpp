// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Union Find

class Solution {
public:
    unordered_map<int, int> U;
    
    int find(int a) {
        if (!U.count(a)) return U[a] = a;
        if (U[a] == a) return a;
        return U[a] = find(U[a]);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        for (int i = 0; i < n; i++) {
            int ui = find(i);
            
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    int uj = find(j);
                    U[uj] = ui;
                }
            }
        }
        
        unordered_map<int, int> rec;
        int conNum = 0;
        for (int i = 0; i < n; i++) {
            int ui = find(i);
            if (!rec[ui]) {
                rec[ui]++; conNum++;
            }
        }
        
        return n - conNum;
    }
};
