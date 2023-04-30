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

void couVec(vector<int>& v) {
    for (int i : v) cout << i << " "; cout << endl;
}

int t, n, m, x;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; cin >> m; cin >> x;

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        vector<pair<int, int> > B;
        for (int i = 0; i < n; i++) B.push_back(make_pair(A[i], i));

        sort(B.begin(), B.end()); reverse(B.begin(), B.end());

        vector<int> H(m);

        vector<int> res(n);

        H[0] += B[0].first; res[B[0].second] = 1;

        for (int i = 1; i < n; i++) {
            int mpos = 0, mv = INT_MAX;

            for (int j = 0; j < m; j++) {
                if (H[m] > mv) {
                    mpos = j; mv = H[m];
                }
            }

            H[mpos] += B[i].first;
            res[B[i].second] = mpos + 1;
        }

        couVec(res);
    }

    return 0;
}