// https://leetcode.com/problems/uncrossed-lines/
// LCS
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        
        int** Benson1 = new int* [m];
        
        for (int i = 0; i < m; i++) {
            Benson1[i] = new int[n];
            for (int j = 0; j < n; j++) Benson1[i][j] = 0;
        } 
        
        for (int i = 0; i < m; i++) {
            if (A[i] == B[0]) Benson1[i][0] = 1;
            else if (i > 0) Benson1[i][0] = Benson1[i - 1][0];
        }
        
        for (int i = 0; i < n; i++) {
            if (A[0] == B[i]) Benson1[0][i] = 1;
            else if (i > 0)  Benson1[0][i] = Benson1[0][i - 1];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                Benson1[i][j] = max(Benson1[i][j - 1], Benson1[i - 1][j]);
                if (A[i] == B[j]) Benson1[i][j] = max(Benson1[i - 1][j - 1] + 1, Benson1[i][j]);
            }
        }
        
        int result = Benson1[m - 1][n - 1];
        
        for (int i = 0; i < m; i++) delete[] Benson1[i];
        delete[] Benson1;
        
        return result;    
    }    
};
