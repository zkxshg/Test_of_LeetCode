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

        int res = 0;
        for (int i : A) if (i != 2) res++;

        cout << res << endl; continue;
    }

    return 0;
}