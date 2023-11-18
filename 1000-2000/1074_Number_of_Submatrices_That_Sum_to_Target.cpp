// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// DP + DFS 
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        // pre sum
        //vector<vector<int> > psum(m, vector<int>(n));
        
        int** psum = new int* [m];
        for (int i = 0; i < m; i++) psum[i] = new int[n];
        
        for (int i = 0; i < n; i++) psum[0][i] = matrix[0][i]; // (0,i)
        // (i,j)
        for (int i = 1; i < m; i++) 
            for (int j = 0; j < n; j++)
                psum[i][j] = psum[i - 1][j] + matrix[i][j];
        
        // loop
        int res = 0;
        for (int x1 = 0; x1 < m; x1++) {
            for (int x2 = x1; x2 < m; x2++) {
                
                int rsum = 0;
                unordered_map<int, int> rres; rres[0] = 1;
                
                for (int y = 0; y < n; y++) {
                    rsum += psum[x2][y] - (x1 ? psum[x1 - 1][y] : 0);
                    if (rres[rsum - target]) res += rres[rsum - target];
                    rres[rsum]++;
                }
            }
        }
        
        for (int i = 0; i < m; i++) delete[] psum[i];
        delete[] psum;
        
        return res;
        
    }
};

// brute-force: O(n^4)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        // pre sum
        //vector<vector<int> > psum(m, vector<int>(n));
        
        int** psum = new int* [m];
        for (int i = 0; i < m; i++) psum[i] = new int[n];
        
        psum[0][0] = matrix[0][0]; // (0,0)
        for (int i = 1; i < m; i++) psum[i][0] = psum[i - 1][0] + matrix[i][0]; // (i,0)
        for (int i = 1; i < n; i++) psum[0][i] = psum[0][i - 1] + matrix[0][i]; // (0,i)
        // (i,j)
        for (int i = 1; i < m; i++) 
            for (int j = 1; j < n; j++)
                psum[i][j] = psum[i -1][j] + psum[i][j - 1] + matrix[i][j] - psum[i - 1][j - 1];
        
        // loop
        int res = 0;
        for (int x1 = 0; x1 < m; x1++) 
            for (int y1 = 0; y1 < n; y1++) 
                for (int x2 = x1; x2 < m; x2++) 
                    for (int y2 = y1; y2 < n; y2++) 
                        if (subSum(psum, x1, y1, x2, y2) == target) res++;

        
        for (int i = 0; i < m; i++) delete[] psum[i];
        delete[] psum;
        
        return res;
        
    }
    
    int subSum(int** ps, int x1, int y1, int x2, int y2) {
        int res = ps[x2][y2];
        if (x1 > 0) res -= ps[x1 - 1][y2];
        if (y1 > 0) res -= ps[x2][y1 - 1];
        if (x1 && y1) res += ps[x1 - 1][y1 - 1];
        return  res;
    }
};
