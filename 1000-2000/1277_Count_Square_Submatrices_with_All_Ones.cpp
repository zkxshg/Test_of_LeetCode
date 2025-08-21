// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// design + BFS
class Solution {
public:
    struct cube {
        int left;
        int right;
        int top;
        int down;
        cube(int xl, int xr, int yl, int yr) : left(xl), right(xr), top(yl), down(yr) {}
    };
    
    int countSquares(vector<vector<int>>& matrix) {
        int len = matrix.size(), wid = matrix[0].size(), result = 0;
        int minl = min(len, wid);
        vector<cube> cubes;
        vector<cube> nextCubes;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                cube tempC(i, i, j, j);
                if (matrix[i][j]) {
                    result++;
                    cubes.push_back(tempC);
                }   
            }
        }
        
        for (int i = 1; i < minl; i++) {
            for (cube cub : cubes) {
                if (cub.right == len - 1 || cub.down == wid - 1) continue;
                bool fake = false;
                for (int i = cub.left; i <= cub.right + 1; i++) {
                    if (!matrix[i][cub.down + 1]) {
                        fake = true;
                        break;
                    } 
                }
                if (fake) continue;
                for (int i = cub.top; i <= cub.down + 1; i++) {
                    if (!matrix[cub.right + 1][i]) {
                        fake = true;
                        break;
                    } 
                }
                if (!fake) {
                    result++;
                    cube tempC(cub.left, cub.right + 1, cub.top, cub.down + 1);
                    nextCubes.push_back(tempC);
                }
            }
            cubes = nextCubes;
            nextCubes.clear();
        }
        return result;
    }
};
