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

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        unordered_map<int, int> D;
        D[A[0]] = 1; int cou = 1;
        for (int i : A) {
            if (!D[A[i]]) {
                cou++; D[A[i]] = cou;
            }
        }

        vector<vector<int>> st(n,  vector<int>(n + 1));
        st[0][1]++;
        for (int i = 1; i < n; i++) {
            int ind = D[A[i];
            for (int j = 1; j <= n; j++) {
                if (j == ind) st[i][ind] = st[i - 1][ind] + 1;
                else st[i][j] = st[i - 1][j];
            }
        }

        vector<int> ress(n + 1, -1);
        for (int i = 0; i < n; i++) {
            int ind = D[A[i];
            if (ress[ind] <= 0) ress[ind];
            else ress[ind] = (ress[ind] + 1) * ress[ind];
        
        }

        int res = 1;

        cout << res << endl; continue;
    }

    return 0;
}