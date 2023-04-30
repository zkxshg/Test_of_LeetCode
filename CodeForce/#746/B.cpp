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

int t, n, x;

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> n >> x; 

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        if (n >= 2 * x + 1) {
            cout << "YES" << endl; continue;
        }

        vector<int> B = A;
        sort(B.begin(), B.end());

        if (n <= x) {
            bool can1 = true;
            for (int i = 0; i < n; i++) {
                if (A[i] != B[i]) {
                    cout << "NO" << endl; can1 = false; break;
                }
            }

            if (can1) cout << "YES" << endl;
            continue;
        }

        int mi = B[0], ma = B.back();

        bool can = true;

        for (int i = 0; i < n; i++) {
            if (A[i] == B[i]) continue;
            else if (i >= x) continue;
            else if (n  - 1 - i >= x) continue;
            else {
                cout << "NO" << endl; can = false;  break;
            }
        }

        if (can) cout << "YES" << endl;
    }

    return 0;
}