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

    while (t) {
        t--;

        cin >> n; 

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        if (n == 1) {
            cout << "YES\n"; continue;
        }

        int maskLen = 1 << (n - 1);

        bool res = false;

        for (int i0 = 0; i0 < n; i0++) {
            aim = A[i0];

            bool get = false;
            vector<int> B;
            for (int j = 0; j < n; j++)
                if (j != i0)
                    B.push_back(A[j]);

            for (int i = 0; i < maskLen; i++) {
                int res = 0;

                bitset<32> bits(i);
                for (int j = 0; j < len; j++) {
                    if (bits[j]) res += B[j];
                }

                if (res == aim) {
                    get = true; break;
                }
            }
            if (get) {
                res = true; break;
            }
        
        }
        
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}