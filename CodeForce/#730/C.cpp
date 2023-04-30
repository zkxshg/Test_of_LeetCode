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
#include <iomanip>
#include<numeric.h>

using namespace decimal;
using namespace std;

#define MaxValue 9999999
#define ll long long
#define ld long double


int t;
_Decimal64 E, c, m, p, v;

void turn(ld x, ld y, ld z, ld pre, int num) {
    // P
    E += pre * z * num;

    // C
    if (x > v) {
        if (y) turn(x - v, y + v / 2, z + v / 2, pre * x, num + 1);
        else turn(x - v, 0, z + v, pre * x, num + 1);
    }
    else if (x) {
        if (y) turn(0, y + x / 2, z + x / 2, pre * x, num + 1);
        else E += pre * x * (num + 1);
    }

    // M
    if (y > v) {
        if (x) turn(x + v / 2, y - v, z + v / 2, pre * y, num + 1);
        else turn(0, y - v, z + v, pre * y, num + 1);
    }
    else if (y) {
        if (x) turn(x + y / 2, 0, z + y / 2, pre * y, num + 1);
        else E += pre * y * (num + 1);
    }
}

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        E = 0m;

        cin >> c; cin >> m; cin >> p; cin >> v;

        turn(c, m, p, 1, 1);

        cout << E << endl; continue;
    }

    return 0;
}