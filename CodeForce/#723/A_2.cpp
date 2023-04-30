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

        cin >> n; n *= 2;

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        bool cons = false;

        while (!cons) {
            cons = true;
            for (int i = 0; i < n; i++) {
                int ind = ((i - 1) >= 0) ? i - 1 : i - 1 + n;
                if (A[ind] + A[(i + 1) % n] == 2 * A[i]) cons = false;

                if (!cons) break;
            }

            if (!cons) next_permutation(A.begin(), A.end());
        }
        
        for (int i = 0; i < n; i++) cout << A[i] << " ";
        cout <<  endl; continue;
    }

    return 0;
}