// https://leetcode.com/problems/transpose-matrix/
// math

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > m_t(n, vector<int>(m));
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) m_t[j][i] = matrix[i][j];
        return m_t;
    }
};
