// https://leetcode.com/problems/assign-cookies/
// Greedy + two pointers

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size(), mpos = 0, npos = 0, res = 0;
        sort(g.begin(), g.end()); sort(s.begin(), s.end());
        
        while (mpos < m && npos < n) {
            if (g[mpos] <= s[npos]) {
                res++; mpos++; npos++;
            }
            else npos++;
        }
        
        return res;
    }
};
