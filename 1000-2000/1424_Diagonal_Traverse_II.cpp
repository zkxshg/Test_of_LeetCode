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

// sorting
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                arr.push_back({i + j, -i, nums[i][j]});
            }
        }

        sort(arr.begin(), arr.end());

        vector<int> result;
        for (const auto& [d, r, val] : arr) {
            result.push_back(val);
        }

        return result;
    }
};
