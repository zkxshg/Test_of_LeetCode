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

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n;

        string s;
        cin >> s;

        int zeros = 0;
        for (char ch : s)
            if (ch == '0') zeros++;

        if (zeros < 3) {
            cout << "BOB" << endl; continue;
        }
        else if (zeros == 3) {
            cout << "ALICE" << endl; continue;
        }

        if (zeros % 2) cout << "ALICE" << endl;
        else cout << "BOB" << endl;

    }

    return 0;
}