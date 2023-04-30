// greedy
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int num = points.size(); if (num < 2) return num;
        
        sort(points.begin(), points.end());
        
        for (int i = 0; i < num - 1; i++) {
            if (points[i][1] >= points[i + 1][0]) {
                points[i + 1][1] = min(points[i][1], points[i + 1][1]);
                points[i][0] = 0; points[i][1] = -1;
            }
        }
        
        int result = 0;
        for (int i = 0; i < num; i++) {
            if (points[i][1] >= points[i][0]) result++;
        }
        return result;
    }
};
