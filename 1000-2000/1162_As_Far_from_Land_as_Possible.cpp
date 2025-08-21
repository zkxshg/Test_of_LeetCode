// https://leetcode.com/problems/as-far-from-land-as-possible/
// DP

class Solution {
public:
    vector<vector<int>> deepCopy(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int> > dc(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dc[i][j] = grid[i][j];
        
        return dc;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int sum = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)  
                sum += grid[i][j];
        if (sum == 0 || sum == m * n) return -1;

        
        vector<vector<int> > pre = grid;
        int res = 0; bool stop = false;;
        
        
        while (!stop) {
            stop = true;
            
            vector<vector<int> > nex = deepCopy(pre);
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (pre[i][j]) continue;
                    
                    if (i > 0 && pre[i - 1][j]) nex[i][j] = 1;
                    if (j > 0 && pre[i][j - 1]) nex[i][j] = 1;
                    if (i < m - 1 && pre[i + 1][j]) nex[i][j] = 1;
                    if (j < n - 1 && pre[i][j + 1]) nex[i][j] = 1;
                    
                    if (!nex[i][j]) stop = false;
                }
            }
            
            pre = nex;
            res++;
        }
        
        return res;
    }
};
