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

        vector<int> B = A;
        sort(B.begin(), B.end());

        int mi = B[0], ma = B.back();

        bool can = true;
        for (int i = 0; i < n; i++) {
            if (A[i] == B[i]) continue;
            else if (abs(A[i] - B[i]) >= x) continue;
            else if ((A[i] - mi >= x && B[i] - mi >= x) || (ma - A[i] >= x && ma - B[i] >= x)) continue;
            else {
                cout << "NO" << endl; can = false;  break;
            }
        }

        if (can) cout << "YES" << endl;
    }

    return 0;
}