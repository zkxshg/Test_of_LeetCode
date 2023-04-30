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

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; n *= 2;

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        vector<int> res; 
        res.push_back(A[0]); res.push_back(A[1]);

        for (int i = 2; i < n; i++) {
            int len = res.size();

            bool get = false;
            for (int j = 0; j < len; j++) {
                if (res[j] + res[(j + 1) % len] != 2 * A[i]) {

                    if (2 * res[(j + 1) % len] != A[i] + res[(j + 2) % len]) {

                        int ind = ((j - 1) >= 0) ? j - 1 : j - 1 + len;
                        if (2 * res[j] != A[i] + res[ind]) {
                            res.insert(res.begin() + j + 1, A[i]);
                            get = true;
                        }
                    
                    }
                    
                }

                if (get) break;
            }

            if (!get) {
                A.push_back(A[i]); A.erase(A.begin() + i); i--;
            }
        }
        
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout <<  endl; continue;
    }

    return 0;
}