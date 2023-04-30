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

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        if (A[0] == 1 || A.back() == n) {
            bool sorted = true;
            for (int i = 0; i < n; i++) {
                if (A[i] != i + 1) {
                    sorted = false; break;
                }
            }

            if (sorted) {
                cout << 0 << endl; continue;
            }
            else {
                cout << 1 << endl; continue;
            }
        }

        if (A[0] == n && A.back() == 1) {
            cout << 3 << endl; continue;
        }

        cout << 2 << endl;
    }

    return 0;
}