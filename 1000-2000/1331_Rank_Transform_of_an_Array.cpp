// https://leetcode.com/problems/rank-transform-of-an-array/?envType=daily-question&envId=2024-10-02
// Hash table

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> sarr = arr;
        sort(sarr.begin(), sarr.end());

        unordered_map<int, int> rank;
        int R = 0, pre = INT_MIN;
        for (int i : sarr) {
            if (i != pre) {
                R++; pre = i;
            }
            rank[i] = R;
        }

        for (int i = 0; i < n; i++) arr[i] = rank[arr[i]];
        
        return arr;
    }
};
