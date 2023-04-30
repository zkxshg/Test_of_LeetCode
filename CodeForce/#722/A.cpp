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

        int res = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] == A[0]) res++;
            else break;
        }

        cout << n - res << endl; continue;
    }

    return 0;
}