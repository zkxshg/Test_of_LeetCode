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
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> dia(n);
    for (int i = 0; i < n; i++) cin >> dia[i];


    vector<vector<int> > M(n, vector<int>(n));
    for (int i = 0; i < n; i++)  M[i][i] = dia[i];
    
    for (int i = 0; i < n; i++) {
        int k = dia[i] - 1;
        int x = i, y = i;
        while (k > 0) {
            if (y > 0 && !M[x][y - 1]){
                M[x][y - 1] = dia[i];
                y = y - 1;
                k--;
            }
            else if (x < n - 1 && !M[x + 1][y]) {
                M[x + 1][y] = dia[i];
                x = x + 1;
                k--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << M[i][j] << " ";
        cout << endl;
    }


    return 0;
}