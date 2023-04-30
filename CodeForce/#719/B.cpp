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

int level(int a) {
    int lv = 0;
    while (a) {
        a /= 10; lv++;
    }
    return lv;
}


int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        cin >> n;

        int res = 0;
        int lv = level(n);

        res += (lv - 1) * 9; // low level

        int f = n / pow(10, lv - 1);
        res += f - 1; // low in same lv;

        if (lv < 2) res++; // if ordinary
        else {
            ll oo = f;
            for (int i = 0; i < lv - 1; i++) oo = oo * 10 + f;

            if (n >= oo) res++;
        }

        cout << res << endl;
    }

    return 0;
}