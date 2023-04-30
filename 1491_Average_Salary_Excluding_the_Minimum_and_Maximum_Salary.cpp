// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
// sorting

class Solution {
public:
    double average(vector<int>& salary) {
        int minV = INT_MAX, maxV = INT_MIN, n = salary.size();
        double res = 0;
        for (int i : salary) {
            res += i; minV = min(minV, i); maxV = max(maxV, i);
        }
        res -= minV; res -= maxV;
        return res / (n - 2);
    }
};
