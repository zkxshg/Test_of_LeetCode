// 1504. Count Submatrices With All Ones
// Link: https://leetcode.com/problems/count-submatrices-with-all-ones/
// Lang: C++
// Date: 2025-08-21 20:46:56.134 UTC

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<int> heights(n, 0);
        long long ans = 0;

        for (int i = 0; i < m; ++i) {

            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) heights[j] += 1;
                else heights[j] = 0;
            }

            long long cur = 0;
            vector<pair<int,int>> st;

            for (int j = 0; j < n; ++j) {
                int h = heights[j];
                int cnt = 1;  

                while (!st.empty() && st.back().first >= h) {
                    cur -= st.back().first * st.back().second;
                    cnt += st.back().second;
                    st.pop_back();
                }

                st.emplace_back(h, cnt);
                cur += h * cnt;

                ans += cur; 
            }
        }
        return ans; 
    }
};
