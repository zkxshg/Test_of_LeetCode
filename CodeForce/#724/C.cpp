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
#include <utility> 
#include <map>

using namespace std;

int gcd(int m, int n) {
    int t = 1;
    while (t != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        string s; cin >> s;

        vector<pair<int, int> > R;
        vector<int> res;
        map<pair<int, int>, int> M;

        int Dnum = 0, Knum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') Dnum++;
            else Knum++;

            int gc = 1;
            if (Dnum && Knum) gc = gcd(Dnum, Knum);
            int tD = Dnum / gc, tK = Knum / gc;

            pair<int, int> tp = make_pair(tD, tK);
            R.push_back(tp);

            if (!Dnum || !Knum) {
                res.push_back(max(Dnum, Knum)); continue;
            }

            if (Dnum == 1 || Knum == 1) {
                res.push_back(1); 
                M[tp] = 1;
                continue;
            }

            int tres = 1;
            if (M.find(tp) != M.end()) {
                tres = M[tp] + 1; M[tp]++;
            }
            else M[tp] = 1;

            res.push_back(tres);
        }

        for (int i : res) cout << i << " "; cout << endl;
            
       
    }

    return 0;
}