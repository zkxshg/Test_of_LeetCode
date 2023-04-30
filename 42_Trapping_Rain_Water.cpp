// https://leetcode.com/problems/trapping-rain-water/
// DP

class Solution {
public:
    #define H height
    int trap(vector<int>& height) {
        int n = H.size(), res = 0;
        
        if (n <= 2) return 0;
        
        vector<int> lh(n); lh[0] = H[0];
        for (int i = 1; i < n; i++) lh[i] = max(lh[i - 1], H[i]);
        
        vector<int> rh(n); rh[n - 1] = H[n - 1];
        for (int i = n - 2; i >= 0; i--) rh[i] = max(rh[i + 1], H[i]);
        
        for (int i = 1; i < n - 1; i++) res += max(min(lh[i], rh[i]) - H[i], 0);
        
        return res;
    }
};
