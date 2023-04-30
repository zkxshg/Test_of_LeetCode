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

        vector<pair<int, int>> A(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> A[i].first; cin >> A[i].second;
        }

        

        unordered_map<int, vector<int>> edge;

        for (int i = 1; i <= n - 1; i++) { 
            int a, b; cin >> a; cin >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        int st = 1;
        while (edge[st].size() > 1 && st < n) st++;

        ll lsum = 0, rsum = 0;

        vector<int> nex; nex.push_back(st);

        bool left = true;
        unordered_map<int, bool> F; F[st] = true;

        vector <pair<bool, bool>> C(n + 1); 

        while (!nex.empty()) {
            vector<int> tem;
            for (int i : nex) {
                for (int j : edge[i]) {
                    if (!F[j]) {
                        int li, ri;
                        li = (!C[i].first) ? A[i].first : A[i].second;
                        ri = (!C[i].second) ? A[i].second : A[i].first;

                        if (abs(A[j].second - li) > abs(A[j].first - li)) {
                            lsum += abs(A[j].second - li); C[j].first = true;
                        }
                        else {
                            lsum += abs(A[j].first - li); C[j].first = false;
                        }
                 
                        
                        if (abs(A[j].second - ri) > abs(A[j].first - ri)) {
                            rsum += abs(A[j].second - ri); C[j].second = false;
                        }
                        else {
                            rsum += abs(A[j].first - ri); C[j].second = true;
                        }

                        F[j] = true; tem.push_back(j);
                    }
                }
            }
            nex = tem;
        }

        cout << max(lsum, rsum) << endl; continue;
    }

    return 0;
}