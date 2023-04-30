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

    while (t) {
        t--;
        cin >> n; 

        int res = 1, tem = 1; n -= 1;
        while (n > 0) {
            tem += 2;
            n -= tem;
            res++;
        }

        cout << res << endl; continue;
    }

    return 0;
}