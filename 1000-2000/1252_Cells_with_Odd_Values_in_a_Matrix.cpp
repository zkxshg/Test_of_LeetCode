//https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
//design
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        if (indices.size() == 0) return 0;
        if (n == 0 || m == 0) return 0;
        vector<vector<int>> Mat(n, vector<int>(m));
        for (int i = 0; i < indices.size(); i++){
            int inn = indices[i][0];
            int inm = indices[i][1];
            for (int j = 0; j < m; j++) Mat[inn][j]++;
            for (int j = 0; j < n; j++) Mat[j][inm]++;
        }
        int counter = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (Mat[i][j] & 1) counter++;
            }
        }
        return counter;
    }
};
