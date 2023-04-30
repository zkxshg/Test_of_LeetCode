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

int gcd(int m, int n) {
    int t = 1;
    while (t != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        cin >> n;

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        vector<vector<int> > res;

        for (int i = 0; i < n - 1; i++) {
            int a = A[i], b = A[i + 1];
            if (gcd(a, b) == 1)continue;
            else {
                while (gcd(A[i], A[i + 1]) != 1 || (i != 0 && gcd(A[i], A[i - 1]) != 1)) {
                    int *p = A[i] <= A[i + 1] ? &A[i + 1] : &A[i];
                    *p = (*p % 2000000000 + rand() + 1);
                }
                res.push_back({ i + 1, i + 2, A[i], A[i + 1] });
            }
        }

        cout << res.size() << endl;
        for (vector<int>& v : res) {
            for (int i : v) cout << i << " "; cout << endl;
        }

        //for (int i : A) cout << i << ","; cout << endl;
    }

    return 0;
}