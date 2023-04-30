// https://leetcode.com/problems/brick-wall/
// hash table
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int lv = wall.size();
        
        unordered_map<int, int> interP;
        for (vector<int> v : wall) {
            int wid = 0;
            for (int i = 0; i < v.size() - 1; i++) {
                wid += v[i];
                interP[wid]++;
            }
        }
        
        int res = 0;
        for (auto& v : interP) res = max(v.second, res);
        return lv - res;
    }
};
