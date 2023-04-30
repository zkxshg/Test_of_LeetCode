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
#include <deque>

using namespace std;

int t, a, b, c;

int get_len(int a) {
    int l = 0;
    while (a) {
        a /= 10;
        l++;
    }
    return l;
}

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;

        cin >> a; cin >> b; cin >> c;

        int gcd = pow(10, c - 1);

        int x = gcd, y = gcd;

        if (a != c) 
            while (get_len(x) < a) 
                x *= 2;
       
        if (b != c)
            while (get_len(y) < b)
                y *= 3;

        cout << x << " "<< y << endl;
    }

    return 0;
}