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

using namespace std;

#define MaxValue 9999999
#define ll long long

ll qmul(ll x, ll y, ll mod)
{
    ll ret = 0;
    while (y) {
        if (y & 1)
            ret = (ret + x) % mod;
        x = x * 2 % mod;
        y >>= 1;
    }
    return ret;
}

int t, n, m, k;

int main() {
    cin >> t;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; cin >> m; cin >> k;

        int x = (n - 1) + n * (m - 1), y = (m - 1) + (n - 1) * m;

        int LB = min(x, y), UB = max(x, y);

        if (k <= UB && k >= LB) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}