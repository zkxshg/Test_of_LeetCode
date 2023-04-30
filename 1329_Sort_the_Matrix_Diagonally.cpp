// https://leetcode.com/problems/sort-the-matrix-diagonally
// sort
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        if (m == 1 || n == 1) return mat;
        
        vector<vector<int>> di(m + n - 1);

        int st = n - 1;
        for (int i = 0; i < m + n - 1; i++) {
            if (st >= 0) {
                int x = 0;
                while (x < m && x + st < n) {
                    di[i].push_back(mat[x][x + st]); x++;
                } 
            }
            else {
                int nst = -st, y = 0;
                while (y < n && y + nst < m) {
                    di[i].push_back(mat[y + nst][y]); y++;
                }
            }
            sort(di[i].begin(), di[i].end());
            st--;
        }

        st = n - 1;
        for (int i = 0; i < m + n - 1; i++) {
            if (st >= 0) {
                int x = 0;
                while (x < m && x + st < n) {
                    mat[x][x + st] = di[i][x]; x++;
                }
            }
            else {
                int nst = -st, y = 0;
                while (y < n && y + nst < m) {
                    mat[y + nst][y] = di[i][y]; y++;
                }
            }
            st--;
        }
        
        return mat;
    }
};
