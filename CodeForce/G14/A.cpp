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

void couVec(vector<int>& v) {
    for (int i : v) cout << i << " "; cout << endl;
}

int t, n, x;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; cin >> x;

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        int sum = 0; for(int i = 0; i < n; i++) sum += A[i];
        if (sum == x) {
            cout << "NO\n"; continue;
        }
        else if (sum < x) {
            cout << "YES\n"; couVec(A); continue;
        }

        sort(A.begin(), A.end()); reverse(A.begin(), A.end());

        bool get = false;
        for (int i = 0; i < n; i++) {
            if (x < A[i]) break;
            else if (x == A[i]) {
                if (i < n - 1) {
                    int tem = A[i]; A[i] = A[i + 1]; A[i + 1] = tem;

                    if (x < A[i]) break;
                    else x -= A[i];
                }
                else {
                    get = true; break;
                
                }
            }
            else x -= A[i];
        }

        if (get) {
            cout << "NO\n"; continue;
        }

        cout << "YES\n"; couVec(A); continue;
    }

    return 0;
}