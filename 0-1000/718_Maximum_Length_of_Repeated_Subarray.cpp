// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// DP

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        vector<vector<int> > mn(m + 1, vector<int>(n + 1));
        
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    mn[i][j] = mn[i - 1][j - 1] + 1;
                    res = max(res, mn[i][j]);
                }
            }
        }
        return res; 
    }
};
