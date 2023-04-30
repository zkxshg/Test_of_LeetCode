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

        if (n < 3) {
            cout << "YES" << endl; continue;
        }

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        vector<pair<int, int> > arr; 
        arr.push_back(make_pair(A[0], A[0]));

        for (int i = 1; i < n; i++) {
            pair<int, int> tp = make_pair(A[i], A[i]);

            int lb = lower_bound(arr.begin(), arr.end(), tp);

            if (2 * i - 1 - lb)
        
        }

    }

    return 0;
}