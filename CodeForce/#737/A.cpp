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

    while (t) {
        t--;

        cin >> n; 

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        int maxIn = 0, maxV = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (A[i] > maxV) {
                maxIn = i; maxV = A[i];
            }
        }

        double a1 = 0, a2 = 0;

        a1 = A[maxIn];

        for (int i = 0; i < n; i++) 
            if (i != maxIn) 
                a2 += A[i];

        a2 /= n - 1;
        a1 += a2;

        cout << setprecision(8) << a1 << endl; continue;
    }

    return 0;
}