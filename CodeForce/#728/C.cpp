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

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        int z; cin >> z;

        if (n == 1) {
            cout << 0 << endl; continue;
        }

        vector<ll> A(n - 1);
        for (int i = 0; i < n - 1; i++) cin >> A[i];

        ll res = 0; ll sum = 0;
        sort(A.begin(), A.end());
        for (int i = 1; i < n - 1; i++) {
            res += A[i] * i - sum; sum += A[i - 1];
        }

        cout << -res << endl; continue;
    }

    return 0;
}