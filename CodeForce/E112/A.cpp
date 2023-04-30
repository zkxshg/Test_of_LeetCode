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

using namespace std;

#define MaxValue 9999999
#define ll long long
#define ull unsigned long long int

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

int t;

int main() {
    cin >> t;

    while (t) {
        t--;
        ull n;

        cin >> n;

        if (n <= 6) {
            cout << 15 << endl; continue;
        }

        ull res;
        if (n % 2) res = (n + 1) / 2 * 5;
        else res = n / 2 * 5;

        cout << res << endl; continue;
    }

    return 0;
}