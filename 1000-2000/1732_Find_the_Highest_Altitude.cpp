// https://leetcode.com/problems/find-the-highest-altitude/
// prefix sum

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, tem = 0;
        for (int i : gain) {
            tem += i; res = max(res, tem);
        }
        return res;
    }
};
