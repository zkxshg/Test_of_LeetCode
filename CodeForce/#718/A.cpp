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

int t;

int main() {
    cin >> t;

    while (t) {
        t--;
        string strn;

        cin >> strn;

        vector<int> nv;
        for (int i = strn.size() - 1; i >= 0; i--) nv.push_back(strn[i]  - '0');

        if (nv.size() < 4) {
            cout << "-1" << endl; continue;
        }

        int tem = 0, res = 0;
        while (tem < 2050 && !nv.empty()) {
            tem = tem * 10 + nv.back();
            nv.pop_back();

            while (tem >= 2050) {
                tem -= 2050; res++;
            }
        }

        if (tem > 0 && nv.empty()) {
            cout << "-1" << endl; continue;
        }
        else {
            cout << res << endl; continue;
        }
    }

    return 0;
}