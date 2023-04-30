// https://leetcode.com/problems/reshape-the-matrix/
// math

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        
        if (m * n != r * c) return mat;
        
        vector<vector<int> > R(r, vector<int>(c));
        
        int pos = 0;
        while (pos < m * n) {
            R[pos / c][pos % c] = mat[pos / n][pos % n]; pos++;
        }
        
        return R;
    }
};
