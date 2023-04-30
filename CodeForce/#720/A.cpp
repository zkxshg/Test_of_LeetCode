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

int t, a, b;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> a; cin >> b;

        if (b == 1) {
            cout << "NO\n";
            continue;
        }

        ll x, y, z;

        ll a1, a2;
        a1 = b - 1; a2 = b + 1;

        x = a1 * a; y = a2 * a; z = x + y;

        cout << "YES\n";
        cout << x << " " << y << " " << z << endl;
    }

    return 0;
}