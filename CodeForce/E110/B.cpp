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

int gcd(int m, int n) {
    int t = 1;
    while (t != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
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
        for (int i = 0; i < n; i++) cin >> A[i];

        int evenNum = 0;
        vector<int> odds;

        for (int i : A) {
            if (i % 2 == 0) evenNum++;
            else odds.push_back(i);
        }

        ll res = 0;
        for (int i = 0; i < evenNum; i++) res += n - 1 - i;

        int ol = odds.size();

        sort(odds.begin(), odds.end());

        for (int i = 0; i < ol - 1; i++)
            for (int j = i + 1; j < ol; j++)
                if (gcd(odds[i], odds[j]) > 1)
                    res++;

        cout << res << endl; continue;
    }

    return 0;
}