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

using namespace std;

#define MaxValue 9999999
#define ll long long


int t, n;
vector<int> cand;

int level(int a) {
    int lv = 0;
    while (a) {
        a /= 10; lv++;
    }
    return lv;
}

bool ifSum(int a, int lv) {
    if (a == 0) return true;
    if (a < 11) return false;

    int head = a / pow(10, lv - 1);

    for (int i = 0; i <= lv - 2; i++) {
        int div = cand[i] * pow(10, lv - i - 2) * head;
        if (a >= div) 
            if (ifSum(a - div, level(a - div))) 
                return true;
    }

    return false;
}


int main() {
    cin >> t;
    int caseNum = 1;

    cand.clear();
    cand.push_back(11);
    for (int i = 2; i < 9; i++) cand.push_back(cand[i - 2] * 10 + 1);

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        int lv = level(n);

        

        if (ifSum(n, lv)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}