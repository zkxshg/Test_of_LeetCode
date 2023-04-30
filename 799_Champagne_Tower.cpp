// array
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured < 1) return 0.0;
        
        vector<vector<double> > glass(100, vector<double>(100));
        glass[0][0] = poured;
        
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double left = (glass[i][j] - 1) / 2;
                
                if (left > 0) {
                    glass[i + 1][j] += left;
                    glass[i + 1][j + 1] += left;
                }
            }
        }
        
        return min(1.0, glass[query_row][query_glass]);
    }
};
