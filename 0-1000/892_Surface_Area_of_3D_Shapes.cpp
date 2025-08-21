// geometry
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int x = grid.size(), y = grid[0].size();
        int num = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) num += grid[i][j];
        }
        
        int total = num * 6;
        
        int ver = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) ver += max(grid[i][j] - 1, 0);
        }
        total -= ver * 2;

        int hor = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y - 1; j++) hor += min(grid[i][j], grid[i][j + 1]);
        }
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x - 1; j++) hor += min(grid[j][i], grid[j + 1][i]);
        }
        total -= hor * 2;
        
        return total;
    }
};
