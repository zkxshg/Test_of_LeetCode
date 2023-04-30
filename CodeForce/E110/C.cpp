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
#define ll long long

int t, n;

int main() {
    cin >> t;

    while (t) {
        t--;
        
        string s;
        cin >> s;

        int n = s.size();

        vector<string> ep; vector<int> pos; string t = "";
        for (char ch : s) ep.push_back(t + ch); ll res = n;
        for (int i = 0; i < n; i++) pos.push_back(i);
        

        while (!ep.empty()) {
            vector<string> tem; vector<int> npos;
            inr m = ep.size();
            for (int i = 0; i < m; i++) {
                if (pos[i] + 1 < n) {
                    if (s[pos[i] + 1] == '?' || ep[i].back() != s[pos[i] + 1) {
                        string ns = ep[i];

                        if (ns.back() == '?' && s[pos[i] + 1] == '?') ns += '?';
                        else if (ns.back() == '0') ns += '1';
                        else ns += '0';

                        tem.push_back(ns); npos.push_back(pos[i] + 1);
                        res++;
                    }
                }
            }

            if (tem.empty()) break;
            ep = tem; pos = npos;
        }

        cout << res << endl; continue;
    }

    return 0;
}