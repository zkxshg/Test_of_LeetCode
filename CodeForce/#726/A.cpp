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

        int sum = 0;
        for (int i : A) sum += i;

        if (sum == n) cout << 0 << endl;
        else if (sum > n) cout << sum - n << endl;
        else cout << 1 << endl;
    }

    return 0;
}