// https://leetcode.com/problems/path-crossing/
// Geometry

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int, unordered_map<int, int>> cs;
        
        int coo_x = 0, coo_y = 0; cs[coo_x][coo_y] = 1;
        
        bool cross = false;
        for (char c : path) {
            if (c == 'N') {
                coo_y++;
                if (cs[coo_x][coo_y]) {
                    cross = true; break;
                }
                else cs[coo_x][coo_y] = 1;
            }
            else if (c == 'S') {
                coo_y--;
                if (cs[coo_x][coo_y]) {
                    cross = true; break;
                }
                else cs[coo_x][coo_y] = 1;
            }
            else if (c == 'W') {
                coo_x--;
                if (cs[coo_x][coo_y]) {
                    cross = true; break;
                }
                else cs[coo_x][coo_y] = 1;
            }
            else if (c == 'E') {
                coo_x++;
                if (cs[coo_x][coo_y]) {
                    cross = true; break;
                }
                else cs[coo_x][coo_y] = 1;
            }
        }
        
        return cross;
    }
};
