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
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n;

        vector<int> A(n);

        for (int i = 0; i < n; i += 2) {
            if (i + 1 >= n) break;

            A[i] = i + 2;
            A[i + 1] = i + 1;
        }

        if (n % 2) {
            A[n - 1] = A[n - 2];
            A[n - 2] = n;
        }

        for (int i = 0; i < n; i++) cout << A[i] << " ";

        cout << endl; continue;
    }

    return 0;
}