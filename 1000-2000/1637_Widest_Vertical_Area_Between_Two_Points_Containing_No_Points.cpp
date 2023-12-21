// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
// Sorting + Greedy

class Solution {
public:
    static bool compareNodes(const vector<int>& node1, const vector<int>& node2) {
        // 按照 x 坐标进行比较
        if (node1[0] < node2[0]) {
            return true;
        }
        else if (node1[0] > node2[0]) {
            return false;
        }

        // 如果 x 坐标相同，则按照 y 坐标进行比较
        return node1[1] < node2[1];
    }

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compareNodes);
        int res = 0;
        for (int i = 1; i < points.size(); i++) {
            res = max(points[i][0] - points[i - 1][0], res);
        }
        return res;
    }
};
