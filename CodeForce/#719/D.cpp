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
#include <unordered_map>

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

        unordered_map<int, int> fre;

        int a;
        for (int i = 0; i < n; i++) {
            cin >> a; fre[a - i]++; 
        }

        //int maxF = 0;
        //for (auto& v : fre) maxF = max(maxF, v.second);
        //vector<int> sf(maxF + 1); 
        //for (int i = 0; i < maxF + 1; i++) 

        ll res = 0;
        for (auto& v : fre)
            for (int i = 1; i < v.second; i++)
                res += i;

        cout << res << endl;
    }

    return 0;
}