// https://leetcode.com/problems/nth-magical-number/
// binary search

class Solution {
public:
    #define ll long long
    
    const ll ub = 1e9 + 7;
    
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
    
    int gcd(int m, int n) {
        int t = 1;
        while (t != 0) {
            t = m % n;
            m = n;
            n = t;
        }
        return m;
    }

    int lcm(int m, int n) {
        return m * n / gcd(m, n);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        ll LCM = lcm(a, b);
        
        ll st = min(a, b);
        
        ll la = a, lb = b, ln = n;
        ll en = max(la, lb) * ln;
        
        ll mid = (st + en) / 2;
        
        ll tn = 0;
        while (st <= en) {
            mid = (st + en) / 2;
            
            tn = mid / a;
            tn += mid / b;
            tn -= mid / LCM;
            // cout << mid << "->" << tn << endl;
            
            if (tn > n) en = mid;
            else if (tn < n) st = mid + 1;
            else {
                if (mid % a && mid % b) en = mid;
                else if (tn == n && (!(mid % a) || !(mid % b))) return mid % ub;
            }
        }
        
        return mid % ub;
    }
};
