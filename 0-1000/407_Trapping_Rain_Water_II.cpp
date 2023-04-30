// https://leetcode.com/problems/trapping-rain-water-ii/submissions/
// BFS

class Solution {
public:
    #define hm heightMap
    
    void cmpH(vector<vector<int> >& H, 
               vector<vector<int>>& M, int x, int y, int x1, int y1) {
        int height = H[x][y];
        
        if (height <= M[x1][y1]) { // meet block
            if (H[x1][y1] != M[x1][y1]) {
                H[x1][y1] = M[x1][y1]; flood(H, M, x1, y1);
            }
        }
        else {
            if (H[x1][y1] < 0) {
                H[x1][y1] = height; flood(H, M, x1, y1);   
            }
            else if (height < H[x1][y1]){
                H[x1][y1] = height; flood(H, M, x1, y1);
            }
        }
    }
    
    void flood(vector<vector<int> >& H, 
               vector<vector<int>>& M, int x, int y) {
        int m = M.size(), n = M[0].size();
        
        if (x - 1 > 0) cmpH(H, M, x, y, x - 1, y);
        if (x + 1 < m - 1) cmpH(H, M, x, y, x + 1, y);
        if (y - 1 > 0) cmpH(H, M, x, y, x, y - 1);
        if (y + 1 < n - 1) cmpH(H, M, x, y, x, y + 1);
    }
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = hm.size(), n = hm[0].size();
        if (m < 3 || n < 3) return 0;
        
        set<pair<int, int> > bfs;
        vector<vector<int> > maxH(m, vector<int>(n, -1));
        
        // boundary condition
        for (int i = 1; i < n - 1; i++) { maxH[0][i] = hm[0][i]; bfs.insert({0, i});}

        for (int i = 1; i < n - 1; i++) { maxH[m - 1][i] = hm[m - 1][i]; bfs.insert({m - 1, i});}

        for (int i = 1; i < m - 1; i++) { maxH[i][0] = hm[i][0];  bfs.insert({i, 0});}

        for (int i = 1; i < m - 1; i++) { maxH[i][n - 1] = hm[i][n - 1];  bfs.insert({i, n - 1});}
        
        for (auto& p : bfs) flood(maxH, hm, p.first, p.second);

        // for(int i=0;i<m;i++){for(int j=0;j<n;j++) cout<<maxH[i][j] << ","; cout << endl;}
        
        int res = 0;
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++)
                 if (maxH[i][j] > hm[i][j]) res += maxH[i][j] - hm[i][j];
         }
        
        return res;
    }
};
