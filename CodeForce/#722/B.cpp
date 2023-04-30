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

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        sort(A.begin(), A.end());

        while (A.back() > 0 && A.size() > 1) {
            if (A[A.size() - 2] > 0) A.pop_back();
            else break;
        }

        int res = A.size(), pos = A.back();

        for (int i = 1; i < res; i++) {
            if (abs(A[i] - A[i - 1]) < pos) {
                res--; break;
            }
        }

        cout << res << endl; continue;
    }

    return 0;
}