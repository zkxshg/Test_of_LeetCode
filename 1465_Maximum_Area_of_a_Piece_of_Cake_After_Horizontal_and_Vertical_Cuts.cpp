// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// math
class Solution {
public:
    # define ll long long

    ll qmul(ll x, ll y, ll mod) {
        ll ret = 0;
        while (y) {
            if (y & 1) ret = (ret + x) % mod;
            x = x * 2 % mod;
            y >>= 1;
        }
        return ret;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        ll maxh = 0, maxw = 0;
        ll preh = 0, prew = 0;
        
        for (int i : horizontalCuts) {
            maxh = max(maxh, i - preh); preh = i;
        } maxh = max(maxh, h - preh);
        
        for (int i : verticalCuts) {
            maxw = max(maxw, i - prew); prew = i;
        } maxw = max(maxw, w - prew);
        
        ll ub = 1e9 + 7;
        return qmul(maxh, maxw, ub);
    }
};
