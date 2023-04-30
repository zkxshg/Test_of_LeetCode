// array
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 1) return {{1}};
        if (n == 2) return {{1,2}, {4,3}};
        
        // 0:right; 1:down; 2:left; 3:top;
        int direction = 0, ele = 1, x = 0, y = 0;
        vector<vector<int> > mat(n, vector<int>(n, -1));
        
        bool finish = false;
        while (!finish) {
            if (direction == 0) {
                while (y < n) {
                    if (mat[x][y] < 0) mat[x][y] = ele++;
                    
                    if (y + 1 < n && mat[x][y + 1] < 0) y++;
                    else break;
                }
            }
            else if (direction == 1) {
                while (x < n)  {
                    if (mat[x][y] < 0) mat[x][y] = ele++;
                    
                    if (x + 1 < n && mat[x + 1][y] < 0) x++;
                    else break;
                }
            }
            else if (direction == 2) {
                while (y >= 0) {
                    if (mat[x][y] < 0) mat[x][y] = ele++;
                    
                    if (y - 1 >= 0 && mat[x][y - 1] < 0) y--;
                    else break;
                }
            }
            else {
                while (x >= 0) {
                    if (mat[x][y] < 0) mat[x][y] = ele++;
                    
                    if (x - 1 >= 0 && mat[x - 1][y] < 0) x--;
                    else break;
                }
            }
            
                           
            if (x < n - 1 && x > 0 && y < n - 1 && y > 0) {
                if (mat[x + 1][y] > 0 && mat[x - 1][y] > 0 && mat[x][y + 1] > 0 && mat[x][y - 1] > 0) {
                    finish = true;
                    break;
                }
            }
                     
            direction = (direction + 1) % 4;         
        }
        
        return mat;
    }
    
};
