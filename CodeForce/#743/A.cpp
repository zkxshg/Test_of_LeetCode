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

        cin >> n; 

        int res = 0;

        char num = '0';
        for (int i = 0; i < n - 1; i++) {
            cin >> num;
            if (num != '0') res += (num - '0') + 1;
        }

        // num[n]
        cin >> num;
        if (num != '0') res += (num - '0');

        cout << res << endl; continue;
    }

    return 0;
}