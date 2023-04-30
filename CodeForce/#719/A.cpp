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
        cin >> n;
        string s; cin >> s;

        vector<int> dict(26);

        int len = s.size(); dict[s[0] - 'A']++;

        bool dis = false;
        for (int i = 1; i < len; i++) {
            if (s[i] != s[i - 1] && dict[s[i] - 'A']) {
                dis = true; break;
            }
            dict[s[i] - 'A']++;
        }

        if (dis) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}