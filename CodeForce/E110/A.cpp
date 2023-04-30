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

        vector<int> A; int a;
        while (cin >> a) {
            A.push_back(a);

            char ch = getchar();
            if (ch == '\n')
                break;
        }
        
        if (A[0] > A[2] && A[1] > A[2] && A[0] > A[3] && A[1] > A[3]) cout << "NO" << endl;
        else if (A[0] < A[2] && A[1] < A[2] && A[0] < A[3] && A[1] < A[3]) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}