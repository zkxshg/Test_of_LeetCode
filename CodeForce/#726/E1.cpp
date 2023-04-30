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

int n, k;

int main() {
    cin >> n; cin >> k;
    
    string s; cin >> s;

    string res;
    for (int i = 1; i <= n; i++) {
        string ss;
        while (ss.size() < k) {
            int l = k - ss.size();;
            ss += s.substr(0, (l > i ? i : l));
        }
        if (res.empty() || ss < res) res = ss;
    }

    cout << res << endl;

    return 0;
}