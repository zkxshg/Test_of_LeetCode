//BFS
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int len = M.size(); if (len < 1) return M;
        int wid = M[0].size(); if (wid < 1) return M;
        
        vector<vector<int>> result(len, vector<int>(wid));
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) result[i][j] = smooth(M, i, j);
        }
        
        return result;
    }
    
    int smooth(vector<vector<int>>& M, int x, int y){
         int len = M.size(), wid = M[0].size();
        
        int sumup = M[x][y], num = 1;
        
        if (x > 0 && y > 0) {sumup += M[x - 1][y - 1]; num++;} // top-left
        if (x > 0) {sumup += M[x - 1][y]; num++;} // top
        if (y > 0) {sumup += M[x][y - 1]; num++;} // left
        if (x > 0 && y < wid - 1) {sumup += M[x - 1][y + 1]; num++;} // top-right
        if (x < len - 1 && y > 0) {sumup += M[x + 1][y - 1]; num++;} // down-left
        if (x < len - 1) {sumup += M[x + 1][y]; num++;} // down
        if (y < wid - 1) {sumup += M[x][y + 1]; num++;} // right
        if (x < len - 1 && y < wid - 1) {sumup += M[x + 1][y + 1]; num++;} // down-right
        
        int result = floor(sumup / num);
        return result;
    }
};
