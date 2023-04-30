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

int t;

int main() {
    cin >> t;

    while (t) {
        t--;

        int w0, h0;
        cin >> w0 >> h0;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int w2, h2;
        cin >> w2 >> h2;

        int w1 = x2 - x1, h1 = y2 - y1;

        if (w1 + w2 > w0 && h1 + h2 > h0) {
            cout << -1 << endl; continue;
        }

        int res = max(w0, h0);

        if (w1 + w2 <= w0) {
            int row = min(max(w2 - (w0 - x2), 0), max(w2 - x1, 0));
            res = min(row, res);
        }

        if (h1 + h2 <= h0) {
            int col = min(max(h2 - (h0 - y2), 0), max(h2 - y1, 0));
            res = min(col, res);
        }
        
        cout << res << endl; continue;
    }

    return 0;
}