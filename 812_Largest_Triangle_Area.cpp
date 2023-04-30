// https://leetcode.com/problems/largest-triangle-area/
// math

class Solution {
public:
    double triArea(vector<int>& a, vector<int>& b, vector<int>& c) {
        double x1 = a[0], y1 = a[1], x2 = b[0], y2 = b[1], x3 = c[0], y3 = c[1];
        double S = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
        return S;
    }
    
    
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    res = max(res, triArea(points[i], points[j], points[k]));
        return res;
    }
};
