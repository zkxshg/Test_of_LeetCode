// 679. 24 Game
// Link: https://leetcode.com/problems/24-game/
// Lang: C++
// Date: 2025-08-21 20:47:46.995 UTC

class Solution {
public:
    static constexpr double EPS = 1e-6;

    bool dfs(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) return fabs(nums[0] - 24.0) < EPS;

        // Try all unordered pairs (i, j), i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<double> rest;
                rest.reserve(n - 1);
                for (int k = 0; k < n; ++k)
                    if (k != i && k != j) rest.push_back(nums[k]);

                double a = nums[i], b = nums[j];

                // All possible results from a and b
                vector<double> candidates;
                candidates.reserve(6);
                candidates.push_back(a + b);
                candidates.push_back(a - b);
                candidates.push_back(b - a);
                candidates.push_back(a * b);
                if (fabs(b) > EPS) candidates.push_back(a / b);
                if (fabs(a) > EPS) candidates.push_back(b / a);

                for (double v : candidates) {
                    rest.push_back(v);
                    if (dfs(rest)) return true;
                    rest.pop_back();
                }
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        nums.reserve(4);
        for (int x : cards) nums.push_back(static_cast<double>(x));
        return dfs(nums);
    }
};
