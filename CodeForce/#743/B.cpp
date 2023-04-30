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

        vector<int> odd(n);
        for (int i = 0; i < n; i++) cin >> odd[i];

        vector<int> even(n);
        for (int i = 0; i < n; i++) cin >> even[i];

        for (int i = 1; i < n; i++) even[i] = max(even[i], even[i - 1]);

        int res = 2 * n;

        int pos = 0;
        while (res > pos) {
            int cost = upper_bound(even.begin(), even.end(), odd[pos]) - even.begin();
            cost += pos;
            
            res = min(res, cost);
            pos++;
        }

        cout << res << endl; continue;
    }

    return 0;
}