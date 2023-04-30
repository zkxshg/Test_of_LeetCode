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

    while (t) {
        t--;

        cin >> n; 

        string res = "";

        for (int i = 1; i <= n; i++) {
            res = "";

            for (int j = 0; j < i; j++) res += '(';
            for (int j = 0; j < i; j++) res += ')';
            for (int j = 0; j < n - i; j++) res += "()";

            cout << res << endl;
        }
    }

    return 0;
}