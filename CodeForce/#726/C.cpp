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
        for (int i = 0; i < n; i++) cin >> A[i];

        sort(A.begin(), A.end());

        int mi = 0, mp = abs(A[1] - A[0]), res = 0;

        for (int i = 1; i < n - 1; i++) {
            int aba = abs(A[i + 1] - A[i]);
            if (aba < mp) {
                mi = i; mp = aba;
            }
        }

        //vector<int> res;
        //res.push_back(A[mi]); 
        //for (int i = mi + 2; i < n; i++) res.push_back(A[i]);
        //for (int i = 0; i < mi; i++) res.push_back(A[i]);
        //res.push_back(A[mi + 1]);

        cout << A[mi] << " ";
        for (int i = mi + 2; i < n; i++) cout << A[i] << " ";
        for (int i = 0; i < mi; i++) cout << A[i] << " ";
        cout << A[mi + 1] << endl;
    }

    return 0;
}