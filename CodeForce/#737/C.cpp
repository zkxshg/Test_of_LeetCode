#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <map>
#include<unordered_map>
#include <utility> 
#include <iomanip>

using namespace std;

#define MaxValue 9999999
#define ll long long


int t, n, k;;
const int ub = 1e9 + 7;

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



ll factorial(ll n) {
    ll fc = 1;
    for (int i = 1; i <= n; ++i) fc = qmul(fc, i, ub);
    return fc;
}

ll combo(ll n, ll m) {
    if (m == 0 || m == n) return 1;
    ll com = factorial(n) / qmul(factorial(m), factorial(n - m), ub);
    return com;
}

ll permutation(ll n, ll m) {
    ll perm = factorial(n) / factorial(n - m);
    return perm;
}



int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> n >> k; 

        if (k == 0) {
            cout << 1 << endl; continue;
        }

        ll res = 1;

        if (n % 2) {
             ll odd_0 = qpow(2, n - 1);

            for (int i = 1; i <= k; i++) {
                res = qmul(res, odd_0, ub);
                ll even = qpow(2, qmul(k - 1, n, ub));
                res = (res + even) % ub;
            }
        
        }
        else {
            ll even_0 = qpow(2, n - 1);
            res = qpow(even_0, k);
        }

        cout <<  res << endl; continue;
    }

    return 0;
}