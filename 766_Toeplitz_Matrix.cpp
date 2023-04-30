// array
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int len = matrix.size(), wid = matrix[0].size();
        if (len == 1 || wid == 1) return true;
        for (int i = 0; i < len - 1; i++) {
            if (!ifTo(matrix, i, 0)) return false;
        }
        for (int i = 1; i < wid - 1; i++) {
            if (!ifTo(matrix, 0, i)) return false;
        }
        return true;
    }
    
    bool ifTo(vector<vector<int>>& matrix, int x, int y) {
        int len = matrix.size(), wid = matrix[0].size();
        int first = matrix[x][y];
        while (x < len && y < wid) {
            if (matrix[x][y] != first) return false;
            x++;
            y++;
        }
        return true;
    }
};
