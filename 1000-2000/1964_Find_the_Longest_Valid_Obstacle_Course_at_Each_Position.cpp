// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/description/
// DP + binary search

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
        int n = obstacles.size();

        vector<int> ans(n);
        vector<int> dp;

        for (int i = 0; i < n; i++) {
            int obstacle = obstacles[i];
            int it = upper_bound(dp.begin(), dp.end(), obstacle) - dp.begin();

            if (it >= dp.size()) dp.push_back(obstacle);
            else dp[it] = obstacle;
            
            ans[i] = it + 1;

            // for (int i : dp) cout << i << ","; cout << endl;
        }

        return ans;
    }
};
