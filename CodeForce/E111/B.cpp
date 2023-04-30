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

int t, n, a, b;

vector<pair<char, int> > RLE(string& str) {
    vector<pair<char, int> > rle;
    rle.push_back(make_pair(str[0], 1));
    
    for (int i = 1; i < n; i++) {
        if (str[i] == rle.back().first) rle.back().second++;
        else rle.push_back(make_pair(str[i], 1));
    }

    return rle;
}

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> n; cin >> a; cin >> b;

        string str;
        cin >> str;

        if (b >= 0) {
            cout << (b + a) * n << endl; continue;
        }

        vector<pair<char, int> > rle = RLE(str);

        int res = 0; res = n * a + (rle.size() / 2 + 1)* b;
        cout << res << endl; continue;
    }

    return 0;
}