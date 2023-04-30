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

bool cmp(ll a, ll b) {
    return a > b;
}

int t, n;

int main() {
    cin >> t;

    while (t) {
        t--;
        int cost = 0;

        cin >> n;

        vector<int> U(n);
        for (int i = 0; i < n; i++) cin >> U[i];

        vector<int> sk(n);
        for (int i = 0; i < n; i++) cin >> sk[i];

        vector<vector<ll> > stu(n);

        for (int i = 0; i < n; i++) stu[U[i] - 1].push_back(sk[i]);

        for (int i = 0; i < n; i++) sort(stu[i].begin(), stu[i].end(), cmp);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < stu[i].size(); j++) stu[i][j] = stu[i][j - 1] + stu[i][j];
        }

        vector<ll> resN(n);

        vector<int> uni;
        for (int i = 0; i < n; i++) uni.push_back(i);

        for (int r = 1; r <= n; r++) {
            vector<int> temU;

            ll res = 0;

            for (int i : uni) {
                if (stu[i].size() >= r) {
                    res += stu[i][stu[i].size() - stu[i].size() % r - 1];
                    temU.push_back(i);
                }
            }

            uni = temU;
            
            if (!res || uni.empty()) break;

            resN[r - 1] = res;
        }

        for (int i = 0; i < n; i++) cout << resN[i] << " "; cout << endl;

    }
}
