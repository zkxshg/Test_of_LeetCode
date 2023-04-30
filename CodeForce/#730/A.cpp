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

ll gcd(ll m, ll n) {
    ll t = 1;
    while (t != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

int t, n;

int main() {
    cin >> t;

    while (t) {
        t--;

        ll a, b;
        cin >> a; cin >> b;

        if (a == b){
            cout << "0 0" << endl; continue;
        }

        if (!a || !b) {
            cout << abs(a - b) << " 0" << endl; continue;
        }

        ll gab = gcd(a, b);

        ll div = abs(a - b);

        ll low = min(a, b);
        if (a >= div) low = min(a - div, low);
        if (b >= div) low = min(b - div, low);

        ll times = 1;
        ll up = low;
        while (times * div < a || times * div < b) {
            up = min(up, abs(times * div - a));
            up = min(up, abs(times * div - b));
            times++;
        }


        cout <<div << " " << min(low, up) << endl; continue;
    }

    return 0;
}