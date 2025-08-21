// https://leetcode.com/problems/score-after-flipping-matrix/
// Greedy

class Solution {
public:
    vector<vector<int> > M;
    
    void revCol(int col) {
        int m = M.size(), n = M[0].size();
        for (int i = 0; i < m; i++) M[i][col] = 1 - M[i][col];
    }
    
    void revRow(int row) {
        int m = M.size(), n = M[0].size();
        for (int i = 0; i < n; i++) M[row][i] = 1 - M[row][i];
    }
    
    int cal() {
        int m = M.size(), n = M[0].size();
        
        int res = 0;
        
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                res += pow(2, n - 1 - j) * M[i][j];
        
        return res;
    }
    
    void print2D(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << M[i][j]; if (j < n - 1) cout << ",";
            }
            
            cout << endl;
        }
    }
    
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        M = grid;
        
        for (int i = 0; i < m; i++) {
            if (!M[i][0]) revRow(i);
        }
        //print2D(M);
        
        for (int i = 1; i < n; i++) {
            int n1 = 0, n0 = 0;
            
            for (int j = 0; j < m; j++) {
                if (M[j][i]) n1++;
                else n0++;
            }
 
            if (n1 < n0) revCol(i);
        }
        
        // print2D(M);
        
        return cal();
    }
};
