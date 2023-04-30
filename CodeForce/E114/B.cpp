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

int t, a, b, c, m;

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> a >> b >> c >> m;

        int UB = (a - 1) + (b - 1) + (c - 1);

        int maxF = max(a, b); maxF = max(maxF, c);

        int LB = (maxF - 1) - (a + b + c - maxF); LB = max(0, LB);

        if (m <= UB && m >= LB) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}