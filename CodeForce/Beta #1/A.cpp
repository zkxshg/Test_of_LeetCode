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
#define ll long long


int n, m, a;

int main() {
    cin >> n >> m >> a;

    ll row, col;
    row = n / a;  if (n % a) row++;
    col = m / a;  if (m % a) col++;

    cout << row * col << endl;
    return 0;
}