// https://leetcode.com/problems/where-will-the-ball-fall/
// DFS

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<int> res(n, -1);
        
        for (int i = 0; i < n; i++) {
            int x = 0, y = i;
            int rot = 1; // 1:up; 2: right; 3:down; 4:left
            
            while (x < m && y < n) {
                
                if (grid[x][y] > 0) {
                    if (rot == 1) {
                        if (y >= n - 1) break; // meet right wall
                        
                        y++; rot = 4;
                    }
                    else if (rot == 4) {
                        x++; rot = 1;
                    }
                    else break; // meet "V"
                    
                    //if (rot == 2 || rot == 3) break; 
                }
                else {  // grid[x][y] == -1
                    if (rot == 1) {
                        if (y <= 0) break; // meet left wall
                        
                        y--; rot = 2;
                    }
                    else if (rot == 2) {
                        x++; rot = 1;
                    }
                    else break; // meet "V"
                    
                    //if (rot == 3 || rot == 4) break; 
                }
                
                if (x >= m) {
                    res[i] = y; // reach the bottom
                    break;
                } 
            }
        }
        
        return res;
    }
};
