// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
// Combination

class Solution {
public:
    #define MaxValue 9999999
    #define ll long long
    
    ll ub = 1e9 + 7;
    
    ll qmul(ll x, ll y) {
        ll ret = 0;
        while (y) {
            if (y & 1)
                ret = (ret + x) % ub;
            x = x * 2 % ub;
            y >>= 1;
        }
        return ret;
    }
    
    int acc(int n) {
        int res = 0;
        for (int i = n; i > 0; i--) res += i;
        return res;
    }
    
    int countOrders(int n) {
        ll res = 1;
        for (int i = 1; i <= n; i++) res = qmul(res, acc(2 * i - 1)) % ub;
        return res;
    }
};
