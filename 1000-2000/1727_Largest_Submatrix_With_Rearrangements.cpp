// https://leetcode.com/problems/largest-submatrix-with-rearrangements/
// Sorting + Greedy

class Solution {
public:
    static bool cmp(int a, int b) {
        return a > b;
    }

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int> > con(m, vector<int>(n));
        for (int i = 0; i < n; i++){
            if (matrix[0][i]) con[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                con[i][j] = con[i - 1][j];

                if (matrix[i][j]) con[i][j] = con[i - 1][j] + 1;
                else con[i][j] = 0;
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            vector<int> ci = con[i];
            sort(ci.begin(), ci.end(), cmp);

            for (int j = 0; j < n; j++) res = max(res, (j + 1) * ci[j]);
        }

        return res;
    }
};
