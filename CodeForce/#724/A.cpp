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

        sort(A.begin(), A.end());

        if (A[0] < 0) {
            cout << "NO" << endl; continue;
        }

        vector<int> res;
        for (int i = 0; i <= A.back(); i++) res.push_back(i);

        cout << "YES" << endl;
        cout << res.size() << endl;
        for (int i : res) cout << i << " "; cout << endl;


    }

    return 0;
}