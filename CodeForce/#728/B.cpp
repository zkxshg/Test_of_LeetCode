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

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n;

        vector<int> A(n + 1);
        for (int i = 1; i <= n; i++) cin >> A[i];

        int res = 0;

        for (int i = 1; i <= n; i++) {
            int a = A[i];

            int p = 1;

            ll m = p * a;
            while (m <= n + i) {
                if (m > i && A[m - i] == p && p != a)
                    res++;

                p++; m = p * a;
            }
        }

        cout << res / 2 << endl; continue;
    }

    return 0;
}