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
#define ll long long

int t, n, s;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;

        cin >> n;

        unordered_map<int, vector<int>> line;

        bool zero = false; vector<int> bfs; unordered_map<int, int> tran;

        for (int i = 1; i <= n; i++) {
            int s1, s2;

            cin >> s1;
            if (!s1) {
                zero = true; bfs.push_back(i); tran[i] = 1; continue;
            }

            for (int j = 0; j < s1; j++) {
                cin >> s2;
                line[i].push_back(s2);
            }
        }

        if (!zero) {
            cout << -1 << endl; continue;
        }

        int res = 0, num = bfs.size();
        while (!bfs.empty()) {
            vector<int> tem;

            for (int i : bfs) {
                for (int j : line[i]) {
                    if (!tran[j]) {
                        tem.push_back(j); tran[j] = 1; num++;
                    }
                }
            }

            bfs = tem; res++;
        }

        if (num < n) {
            cout << -1 << endl; continue;
        }

        cout << res << endl; continue;
    }

    return 0;
}