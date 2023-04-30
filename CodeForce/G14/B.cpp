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

int t;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        ll n;
        cin >> n; 

        // must divided by 2
        if (n == 1 || n % 2) {
            cout << "NO\n"; continue;
        }

        // if pow of 2
        if (n == pow(2, int(log2(n)))) {
            cout << "YES\n"; continue;
        }

        // max power2 element
        ll l2n = 2;
        while (n % l2n == 0) l2n *= 2;
        l2n /= 2;

        n /= l2n;
        int sn = sqrt(n);
        // if left is square
        if (sn * sn == n) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}