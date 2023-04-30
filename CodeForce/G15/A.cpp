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

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        string s; cin >> s;

        vector<int> A(n); vector<int> sA(n);
        for (int i = 0; i < n; i++) {
            A[i] = s[i] - 'a'; sA[i] = A[i];
        }

        sort(sA.begin(), sA.end());

        int res = 0;
        for (int i = 0; i < n; i++)
            if (A[i] != sA[i])
                res++;

        cout << res << endl; continue;
    }

    return 0;
}