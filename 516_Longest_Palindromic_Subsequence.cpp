// https://leetcode.com/problems/longest-palindromic-subsequence/
// DP

class Solution {
public:
    
    int DP_LCS_Algorithm(int* A, int* B, int m, int n) {

        // 0 Initialize
        int** Benson1 = new int* [m];  // Benson LCSt matrix
        for (int i = 0; i < m; i++) {
            Benson1[i] = new int[n];
            for (int j = 0; j < n; j++) Benson1[i][j] = 0;
        } 

        // 1 boundary conditions
        for (int i = 0; i < m; i++) {
            if (A[i] == B[0]) Benson1[i][0] = 1;
            else if (i > 0) Benson1[i][0] = Benson1[i - 1][0];
        }

        for (int i = 0; i < n; i++) {
            if (A[0] == B[i]) Benson1[0][i] = 1;
            else if (i > 0)  Benson1[0][i] = Benson1[0][i - 1];
        }

        // 2 Use DP to calculate the LCS(i, j)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                Benson1[i][j] = max(Benson1[i][j - 1], Benson1[i - 1][j]);
                if (A[i] == B[j]) Benson1[i][j] = max(Benson1[i - 1][j - 1] + 1, Benson1[i][j]);
            }
        }

        int result = Benson1[m - 1][n - 1];  // M(m-1, n-1) = LCSt(A, B)

        // 3 clear the memory
        for (int i = 0; i < m; i++) delete[] Benson1[i];
        delete[] Benson1;

        return result;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) swap(text1, text2);
        
        int m = text1.size(), n = text2.size();
        if (n < 1 || m < 1) return 0;

        int* A = new int[m];
        for (int i = 0; i < m; i++) A[i] = text1[i] - 'a';
        
        int* B = new int[n];
        for (int i = 0; i < n; i++) B[i] = text2[i] - 'a';

        int res = DP_LCS_Algorithm(A, B, m, n);
        delete[] A;
        delete[] B;

        return res;
    }
    
    int longestPalindromeSubseq(string s) {
        string rs; rs.assign(s.rbegin(), s.rend());
        return longestCommonSubsequence(s, rs);
    }
};
