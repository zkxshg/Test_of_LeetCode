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

int LIS(vector<int>& A, int st) {

    int res1 = 0;
    vector<int> lis; lis.push_back(A[st]); res1++;
    int pos = st + 1;
    while (pos < n) {
        int p = A[pos];

        for (int j = 0; j < lis.size(); j++) {
            if (p < lis[j]) {
                lis[j] = p;
                break;
            }
            else if (j == lis.size() - 1) {
                lis.push_back(p);
                break;
            }
        }

        if (lis.size() >= 3) break;
        else res1++;

        pos++;
    }

    int res2 = 0;
    vector<int> lds; lds.push_back(A[st]); res2++;
    pos = st + 1;
    while (pos < n) {
        int p = A[pos];

        for (int j = 0; j < lds.size(); j++) {
            if (p > lds[j]) {
                lds[j] = p;
                break;
            }
            else if (j == lds.size() - 1) {
                lds.push_back(p);
                break;
            }
        }

        if (lds.size() >= 3) break;
        else res2++;

        pos++;
    }

    return min(res1, res2);
}

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> n;

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        ll res = 0;
        for (int i = 0; i < n; i++) res += LIS(A, i);

        cout << res << endl; continue;
    }

    return 0;
}