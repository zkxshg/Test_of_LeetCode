// https://leetcode.com/problems/minimum-absolute-difference/
// sorting

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size(), minD = INT_MAX;
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) == minD) res.push_back({arr[i - 1], arr[i]});
            else if (abs(arr[i] - arr[i - 1]) < minD) {
                res.clear(); res.push_back({arr[i - 1], arr[i]});
                minD = abs(arr[i] - arr[i - 1]);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
