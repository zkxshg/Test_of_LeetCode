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

        vector<int> sheeps;

        int len = s.size();
        for (int i = 0; i < len; i++) 
            if (s[i] == '*')
                sheeps.push_back(i);

        int sheepNum = sheeps.size();

        if (sheepNum < 1) {
            cout << 0 << endl; continue;
        
        }

        int res = INT_MAX;

        for (int i = 0; i < sheepNum; i++) {
            if (i > 0 && sheeps[i] == sheeps[i - 1] + 1) continue;

            int temR = 0;
            for (int j = 0; j < i; j++) temR += (sheeps[i] - sheeps[j]) - (i - j);
            for (int j = i + 1; j < sheepNum; j++) temR += (sheeps[j] - sheeps[i]) - (j - i);

            if (temR < res) res = temR;
        
        }

        cout << res << endl;
    }

    return 0;
}