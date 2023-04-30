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

ll qmul(ll x, ll y, ll mod)
{
    ll ret = 0;
    while (y) {
        if (y & 1)
            ret = (ret + x) % mod;
        x = x * 2 % mod;
        y >>= 1;
    }
    return ret;
}

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        vector<int> A(n);
        
        int a1, a2, a3;
        for (int i = 0; i < n / 2; i += 2) {
            if (n % 2 && i == n - 1) {
                cout << "? " << 2 << " " << i << " " << i + 1<< " " << 1 << endl;
                cout.flush();
                cin >> a1;

                if (a1 != A[i - 1]) {
                    A[i] = a1; break;
                }
                else {
                    cout << "? " << 1 << " " << i << " " << i + 1 << " " << n - 1 << endl;
                    cout.flush();
                    cin >> a2;
                    A[i] = a2; break;
                }
            
            }

            cout << "? " << 2 << " " << i + 1 << " " << i + 2 << " " << 1 << endl;
            cout.flush();

            cin >> a1;
            cout << "? " << 2 << " " << i + 1 << " " << i + 2 << " " << a1 << endl;
            cout.flush();

            cin >> a2;

            cout << "? " << 1 << " " << i + 1 << " " << i + 2 << " " << n - 1 << endl;
            cout.flush();
            cin >> a3;

            if (a1 == a2) {
                A[i] = a1; A[i + 1] = a3; // pi < pj
            } 
            else {
                A[i + 1] = a1; A[i] = a3; // pi > pj
            } 
        
        }

        cout << "! ";
        for (int i : A) cout << i << " "; cout << endl;
        cout.flush();
    }

    return 0;
}