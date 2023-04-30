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

int t, k;

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> k; 

        char c2i;
        vector<int> A(k);
        for (int i = 0; i < k; i++) {
            cin >> c2i; A[i] = c2i - '0';
        
        } 

        int res = 0;

        // case 1:
        bool case_1 = false;
        for (int i : A) {
            if (i == 4 || i == 6 || i == 8 || i == 9 || i == 1) {
                res = i; case_1 = true; break;
            }
        }

        if (case_1) {
            cout << 1 << endl << res << endl; continue;
        }

        //case 2
        bool case_2 = false;
        for (int i = 1; i < k; i++) {
            if (A[i] == 2 || A[i] == 5) {
                res = A[0] * 10 + A[i]; case_2 = true; break;
            }
        }

        if (case_2) {
            cout << 2 << endl << res << endl; continue;
        }
        
        // case 3
        unordered_map<int, int> fre;
        for (int i : A) {
            if (fre[i]) {
                res = i * 10 + i; break;
            }
            else if (i == 7 && (fre[2] || fre[5])) {
                if (fre[2]) res = 20 + i;
                if (fre[5]) res = 50 + i;
                break;
            }

            fre[i]++;
        }

        cout << 2 << endl << res << endl; continue;
    }

    return 0;
}