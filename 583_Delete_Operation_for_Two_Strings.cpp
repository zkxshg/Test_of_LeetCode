// https://leetcode.com/problems/delete-operation-for-two-strings/
// LCS
class Solution {
public:
    
    vector<vector<int> > succTable(int* A, int m, int alpha) {
    int len = m;
    vector<vector<int> > succesT(alpha + 1, vector<int>(len + 1, len * 10));
  
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 1; j <= alpha; j++) {
            if (A[i] == j) succesT[j][i] = i + 1; 
            else succesT[j][i] = succesT[j][i + 1];
        }
    }
  
    return succesT;
}


int Diagonal_LCS(int* A, int* B, int m, int n, int alphabet) {
    
    int* d_ij = new int[n]; 
    for (int i = 0; i < n; i++) d_ij[i] = n * 10;

    vector<vector<int> > stB = succTable(B, n, alphabet);

    int maxL = 0;
    for (int i = 0; i < m; i++) {
        int pos = 0;
        for (int j = i; j < m; j++) {
            int nexP = stB[A[j]][pos];

            int minCol = min(d_ij[j - i], nexP);
            if (minCol > n) break;

            d_ij[j - i] = minCol;
            maxL = max(maxL, j - i + 1);
            pos = d_ij[j - i];
        }
        if (m - i < maxL) break;
    }

    delete[] d_ij;
    return maxL;
}
    
    
    int minDistance(string word1, string word2) {
        if (word1.size() > word2.size()) {
            string tem = word1;
            word1 = word2;
            word2 = tem;
        }

        int len1 = word1.size(), len2 = word2.size();
        
        int * A = new int[len1];
        for (int i = 0; i < len1; i++) A[i] = word1[i] - 'a' + 1;
        
        int * B = new int[len2];
        for (int i = 0; i < len2; i++) B[i] = word2[i] - 'a' + 1;
        
        int LCS = Diagonal_LCS(A, B, len1, len2, 27);
        
        delete[] A; delete[] B;
        
        int res = len1 + len2 - 2 * LCS;
        return res;
    }
};
