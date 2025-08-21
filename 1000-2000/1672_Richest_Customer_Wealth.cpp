// array
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (vector<int> v : accounts) res = max(accumulate(v.begin(), v.end(), 0), res);
        return res;
    }
};
