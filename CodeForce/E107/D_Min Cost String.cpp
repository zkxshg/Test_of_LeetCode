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

int n, k;

int main() {
    cin >> n; cin >> k;

    string templ = "";

    for (int i = 0; i < 26; i++) {
        templ += 'a' + i; templ += 'a' + i;
    }

    return 0;
}