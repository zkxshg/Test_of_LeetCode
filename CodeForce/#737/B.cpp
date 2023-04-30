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
#include <iomanip>

using namespace std;

#define MaxValue 9999999

int t, n, k;

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> n >> k; 

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        vector<pair<int,int> > SA;
        for (int i = 0; i < n; i++) SA.push_back(make_pair(A[i], i));
        sort(SA.begin(), SA.end());

        int block = 1;
        int pre = SA[0].second;
        for (int i = 1; i < n; i++) {
            if (SA[i].second != pre + 1) block++;
            pre = SA[i].second;
        }

        if (block <= k) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}