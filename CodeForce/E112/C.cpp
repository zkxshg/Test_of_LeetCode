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

int t, m;

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> m; 

        vector<ll> A1(m);
        for (int i = 0; i < m; i++) cin >> A1[i];

        vector<ll> A2(m);
        for (int i = 0; i < m; i++) cin >> A2[i];

        if (m == 1) {
            cout << 0 << endl; continue;
        }

        for (int i = m - 2; i >= 0; i--) A1[i] = A1[i] + A1[i + 1];
        for (int i = 1; i < m; i++) A2[i] = A2[i] + A2[i - 1];

        ll res = min(A1[1], A2[m - 2]);

        for (int i = 1; i < m - 1; i++) {
            ll score = max(A1[i + 1], A2[i - 1]);
            res = min(res, score);
        }


        cout << res << endl; continue;
    }

    return 0;
}