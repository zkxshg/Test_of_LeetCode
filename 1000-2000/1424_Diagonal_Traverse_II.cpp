// https://leetcode.com/problems/diagonal-traverse-ii/description/
// hash table + array

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> dMap;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                dMap[i+j].push_back(nums[i][j]);
            }
        }

        for (auto& [key, vec] : dMap) {
            result.insert(result.end(), vec.rbegin(), vec.rend());
        }

        return result;     
    }
};
