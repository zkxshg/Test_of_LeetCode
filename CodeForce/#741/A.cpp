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

int t, l, r;

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> l >> r; 

        // r < 2l
        if (r - l < l) {
            cout << r - l << endl; continue;
        }

        // r > 2l -> r = m + (m - 1)
        int mid = r / 2;

        int res = mid - 1;

        if (2 * mid + 1 <= r)
            res = max(res, r % (mid + 1));

        cout << res << endl; continue;
    }

    return 0;
}