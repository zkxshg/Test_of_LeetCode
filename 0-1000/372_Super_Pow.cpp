// https://leetcode.com/problems/super-pow/
// math

class Solution {
public:
    #define MaxValue 9999999
    #define ll long long
    
    const int ub = 1337;
    
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
    
    ll qpow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % ub;
            a = a * a % ub;
            b >>= 1;
        }
        return res;
    }
    
    int superPow(int a, vector<int>& b) {
        ll res = 1; int lv = 0;
        while (!b.empty()) {
            ll tem = qpow(a, b.back());
            
            for (int i = 0; i < lv; i++) tem = qpow(tem, 10);
            
            res = qmul(res, tem);

            b.pop_back(); lv++;
        }

        return res;
    }
};
