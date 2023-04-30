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

int t, r, b, d;

int main() {
    cin >> t;

    while (t) {
        t--;
        int cost = 0;

        cin >> r; cin >> b; cin >> d;

        if (r == b) {
            cout << "YES" << endl; continue;
        }

        if (r > b) {
            int tem = r; r = b; b = tem;
        }

        if (r >= double(b) / (d + 1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}