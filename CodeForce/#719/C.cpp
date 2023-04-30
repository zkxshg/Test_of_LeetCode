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

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        if (n == 1) cout << 1 << endl;
        else if (n == 2) cout << -1 << endl;
        else {

            vector<vector<int> > M(3);
            M[0] = { 2, 9, 7 };
            M[1] = { 4, 6, 3 };
            M[2] = { 1, 8, 5 };

            for (int i = 4; i <= n; i++) {
                int cols = pow(i - 1, 2) + 1;
                for (int j = 0; j < i - 1; j++) {
                    M[j].push_back(cols); cols += 2;
                }

                vector<int> newR;
                int Rows = pow(i, 2) - 1;
                for (int j = 0; j < i - 1; j++) {
                    newR.push_back(Rows); Rows -= 2;
                
                }
                newR.push_back(cols);

                M.push_back(newR);
            }
        

            for (vector<int> v : M) {
                for (int i : v) cout << i << " "; cout << endl;
            }
        
        }


    }

    return 0;
}