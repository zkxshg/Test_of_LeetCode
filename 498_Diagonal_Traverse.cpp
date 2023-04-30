// matrix
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int len = matrix.size(); if (len < 1) return {};
        int wid = matrix[0].size(); if (wid < 1) return {};
        
        vector<int> res;
        int x = 0, y = 0; res.emplace_back(matrix[x][y]);
        bool topRight = true;
        
        while (1) {
            if (topRight) {
                if (x - 1 >= 0 && y + 1 < wid) {x = x - 1; y = y + 1; }
                else {
                    if (y + 1 < wid) y = y + 1;
                    else if (x + 1 < len && y + 1 < wid) {x = x + 1; y = y + 1;}
                    else if (x + 1 < len) x = x + 1;
                    else break;
                    
                    topRight = false;
                }
                res.emplace_back(matrix[x][y]);
            }
            else {
                if (x + 1 < len && y - 1 >= 0) {x = x + 1; y = y - 1;}
                else {
                    if (x + 1 < len) x = x + 1;
                    else if (x + 1 < len && y + 1 < wid) {x = x + 1; y = y + 1;}
                    else if (y + 1 < wid) y = y + 1;
                    else break;
                    
                    topRight = true;
                } 
                res.emplace_back(matrix[x][y]);
            }
        }
        
        return res;
    }
};
