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
#include <unordered_map>
#include <utility> 

using namespace std;

#define MaxValue 9999999

int t, n, H;

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> n >> H; 

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        sort(A.begin(), A.end());

        int a = A.back(), b = A[n - 2];

        int res = (H / (a + b)) * 2;
        if (H % (a + b)) {
            res++;
            if ((H % (a + b)) > a) res++;
        }

        cout << res << endl; continue;
    }

    return 0;
}