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

int n, m;

int main() {
    cin >> n >> m;

    vector<int> A(n); char c;
    for (int i = 0; i < n; i++) {
        cin >> c;  A[i] = c - 'a';
    }

    vector<vector<int> > cand(3, vector<int>(3));
    cand[0][1] = 2; cand[0][2] = 1; 
    cand[1][0] = 2; cand[2][0] = 1;
    cand[1][2] = 0; cand[2][1] = 0;

    while (m) {
        m--;      

        int l, r;
        cin >> l >> r;

        if (l == r) {
            cout << 0 << endl; continue;
        }

        if (l + 1 == r) {
            cout << (A[l - 1] == A[r - 1]) << endl; continue;
        }

        vector<int> B(r - l + 1);
        for (int i = l - 1; i < r; i++) B[i - l + 1] = A[i];

        int left = 0, right = 0, len = r - l + 1;

        for (int i = 1; i < len; i++) {
            if (B[i] == B[i - 1]) {
                if (i == 1) B[i] = cand[B[i - 1]][B[i + 1]];
                else B[i] = cand[B[i - 1]][B[i - 2]];

                left++;
            }

            if (i > 1 && B[i] == B[i - 2]) {
                B[i] = cand[B[i - 1]][B[i - 2]]; left++;
            }
        }

        for (int i = l - 1; i < r; i++) B[i - l + 1] = A[i];

        for (int i = len - 2; i >= 0; i--) {
            if (B[i] == B[i + 1]) {
                if (i == len - 2) B[i] = cand[B[i - 1]][B[i + 1]];
                else B[i] = cand[B[i + 1]][B[i + 2]];

                right++;
            }

            if (i < len - 2 && B[i] == B[i + 2]) {
                B[i] = cand[B[i + 1]][B[i + 2]]; right++;
            }
        }

        int res = min(left, right);

        cout << res << endl; continue;
    }

    return 0;
}