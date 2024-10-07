// https://leetcode.com/problems/longest-common-subsequence/
// DP
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        if (n < 1 || m < 1) return 0;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        int LCS = lcs(mat, text1, text2, n-1, m-1);
        return LCS;
    }
    int lcs(vector<vector<int>> & mat, string t1, string t2, int x, int y) {
        if (x == 0 && y == 0) return t1[0] == t2[0];
        else if (x == 0) {
            if (mat[0][y - 1] < 0) mat[0][y - 1] = lcs(mat, t1, t2, 0, y-1);
            if (t1[0] == t2[y]) return 1;
            else return mat[0][y - 1];
        }
        else if (y == 0) {
            if (mat[x - 1][y] < 0) mat[x - 1][0] = lcs(mat, t1, t2, x - 1, 0);
            if (t1[x] == t2[0]) return 1;
            else return mat[x - 1][0];
        }
        
        if (mat[x][y - 1] < 0) mat[x][y - 1] = lcs(mat, t1, t2, x, y-1);
        if (mat[x - 1][y] < 0) mat[x - 1][y] = lcs(mat, t1, t2, x - 1, y);
        
        int result = max(mat[x][y - 1], mat[x - 1][y]);
        if (t1[x] == t2[y]) {
            if (mat[x - 1][y - 1] < 0) mat[x - 1][y - 1] = lcs(mat, t1, t2, x - 1, y-1);
            result = max(result, mat[x - 1][y - 1] + 1);
        }
        return result;
    }
};
