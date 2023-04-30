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

int t, n;

int main() {
    cin >> t;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        vector<vector<int> > rank(n, vector<int>(5));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                cin >> rank[i][j];
        
        if (n == 1) {
            cout << 1 << endl; continue;
        }

        vector<vector<int> > win(n, vector<int>(5));

        for (int i = 0; i < 5; i++) {
            vector<pair<int, int> > sco;
            for (int j = 0; j < n; j++) sco.push_back(make_pair(rank[j][i], j));
            sort(sco.begin(), sco.end());

            for (int j = 0; j < n; j++) {
                win[sco[j].second][i] = j + 1;
            }
        }

        int lpos = 0;
        while (lpos < n){
            bool sup = true;

            for (int j = lpos + 1; j < n; j++) {
                int lose = 0;
                for (int k = 0; k < 5; k++)
                    if (win[lpos][k] >= win[j][k])
                        lose++;

                if (lose > 2) {
                    sup = false; lpos = j; break;
                }
            }

            if (sup) break;
        }

        int rpos = n - 1;
        while (rpos >= 0) {
            bool sup = true;

            for (int j = rpos - 1; j >= 0; j--) {
                int lose = 0;
                for (int k = 0; k < 5; k++)
                    if (win[rpos][k] >= win[j][k])
                        lose++;

                if (lose > 2) {
                    sup = false; rpos = j; break;
                }
            }

            if (sup) break;
        }
       
        if (lpos == rpos) cout << lpos + 1 << endl;
        else cout << -1 << endl;

    }

    return 0;
}