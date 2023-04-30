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

ll sumReverse(vector<ll>& A, vector<ll>& B, int s, int e, ll Ores) {
    // reverse order
    for (int i = s; i <= e; i++) Ores += A[i] * B[e - (i - s)] - A[i] * B[i];
    return Ores;
}


int n;

int main() {
    cin >> n;

    vector<ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<ll> B(n);
    for (int i = 0; i < n; i++) cin >> B[i];

    if (n == 1) {
        cout << A[0] * B[0] << endl; return 0;
    }

    ll res = 0;
    for (int i = 0; i < n; i++) res += A[i] * B[i];

    ll Ores = res;

    // 1<->n -> 1<->2
    for (int j = n - 1; j > 0; j--) {
        ll Rres = sumReverse(A, B, 0, j, Ores);
        res = max(res, Rres);

        for (int i = 0; i < j / 2; i++) {
            Rres += (A[i] * B[i] + A[j - i] * B[j - i] - A[i] * B[j - i] - A[j - i] * B[i]);
            res = max(res, Rres);
        }
    }

    // 2<->n -> 3<->n -> ... -> (n-1)<->n
    for (int i = 1; i < n - 1; i++) {
        ll Rres = sumReverse(A, B, i, n - 1, Ores);
        res = max(res, Rres);

        for (int j = 0; j < (n - 1 - i) / 2; j++) {
            Rres += (A[i + j] * B[i + j] + A[n - 1 - j] * B[n - 1 - j] - A[i + j] * B[n - 1 - j] - A[n - 1 - j] * B[i + j]);
            res = max(res, Rres);
        }
    
    }

    cout << res << endl;

    return 0;
}
