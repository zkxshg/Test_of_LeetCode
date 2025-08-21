// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
// math
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int plen = points.size(), qlen = queries.size();
        vector<int> res(qlen);
        
        for (vector<int> p : points) {
            for (int i = 0; i < qlen; i++)
                if (dist(p[0], p[1], queries[i][0], queries[i][1]) <= queries[i][2] * queries[i][2])
                    res[i]++;
        }
        
        return res;
        
    }
    
    int dist(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
};
