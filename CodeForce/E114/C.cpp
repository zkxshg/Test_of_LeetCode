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

int n, m;
ll def, atk;

int main() {
    cin >> n;

    ll sumDef = 0;
    vector<ll> heros(n); 
    for (int i = 0; i < n; i++) {
        scanf("%lld", &heros[i]); sumDef += heros[i];
    }
    sort(heros.begin(), heros.end());

    cin >> m;

    while (m) {
        m--;

        cin >> def; cin >> atk;

        ll res = 0, zero = 0;

        // 1 Boundary
        // 1.1 UB
        if (def >= heros.back()) {
            res += def - heros.back();
            res += max(atk - (sumDef - heros.back()), zero);
            cout << res << endl; continue;
        }

        // 1.2 LB
        if (def <= heros[0]) {
            res += max(atk - (sumDef - heros[0]), zero);
            cout << res << endl; continue;
        }

        // 2 inside
        int pos = lower_bound(heros.begin(), heros.end(), def) - heros.begin();

        // use stronger
        ll res1 = max(atk - (sumDef - heros[pos]), zero);

        // use weaker
        ll res2 = def - heros[pos - 1];
        res2 += max(atk - (sumDef - heros[pos - 1]), zero);
        
        res = min(res1, res2);
        cout << res << endl; continue;
    }


    return 0;
}