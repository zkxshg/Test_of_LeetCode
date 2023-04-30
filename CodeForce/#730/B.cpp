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

        ll sum = 0; for (int i : A) sum += i;

        ll mod = sum % n; ll mean = sum / n;

        ll res = mod * (n - mod);

        cout << res << endl; continue;
    }

    return 0;
}