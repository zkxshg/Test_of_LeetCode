// switch-case
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        
        int dir = 0, x = 0, y = 0;
        for (int i = 0; i < m * n; i++) {
            switch(dir) {
                case 0: {
                    res.push_back(matrix[x][y]); matrix[x][y] = 101;
                    if (y >= n - 1 || matrix[x][y + 1] > 100) {
                        dir = 1; x++;
                    } 
                    else y++;
                    break;
                }
                case 1: {
                    res.push_back(matrix[x][y]); matrix[x][y] = 101;
                    if (x >= m - 1 || matrix[x + 1][y] > 100) {
                        dir = 2; y--;
                    } 
                    else x++;
                    break;
                }
                    
                case 2: {
                    res.push_back(matrix[x][y]);
                    matrix[x][y] = 101;
                    if (y <= 0 || matrix[x][y - 1] > 100) {
                        dir = 3; x--;
                    } 
                    else y--;
                    break;
                }
                    
                case 3: {
                    res.push_back(matrix[x][y]);
                    matrix[x][y] = 101;
                    if (x <= 0 || matrix[x - 1][y] > 100) {
                        dir = 0; y++;
                    } 
                    else x--;
                    break;
                }    
            }
        }
        return res;
    }
    
};
