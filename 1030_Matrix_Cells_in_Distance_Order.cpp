// https://leetcode.com/problems/matrix-cells-in-distance-order/
// Matrix + hash table

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        unordered_map<int, vector<pair<int, int>> > eles;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int dis = abs(i - rCenter) + abs(j - cCenter);
                eles[dis].push_back(make_pair(i, j));
            }
        }
        
        vector<vector<int>> res;
        
        int d = 0;
        while (!eles[d].empty()) {
            for (auto& p : eles[d]) res.push_back({p.first, p.second});
            d++;
        }
        
        return res;
    }
};
