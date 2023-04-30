// array
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = INT_MAX, ind = -1, len = points.size();
        for (int i = 0; i < len; i++) {
            vector<int> v = points[i]; 
            if (x == v[0] || y == v[1]) {
                int div = abs(x - v[0]) + abs(y - v[1]);
                if (div < res) {
                    ind = i;
                    res = div;
                }
            }
        }
        return ind;
    }
};
