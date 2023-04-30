#include <utility> 
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

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
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

        vector<pair<int, int> > st;
        for (int i = 0; i < n; i++) st.push_back(make_pair(sk[i], U[i]));
        sort(st.begin(), st.end(), cmp);

        vector<vector<int> > stu(n, vector<int>(1));

        for (int i = 0; i < n; i++) stu[st[i].second - 1].push_back(stu[st[i].second - 1].back() + st[i].first);

        vector<int> resN(n);

        for (int r = 1; r <= n; r++) {
            int res = 0;

            for (int i = 0; i < n; i++)
                if (stu[i].size() > r)
                    res += stu[i][stu[i].size() - (stu[i].size() - 1) % r - 1];

            resN[r - 1] = res;
        }

        for (int i = 0; i < n; i++) cout << resN[i] << " "; cout << endl;

    }

    return 0;
}