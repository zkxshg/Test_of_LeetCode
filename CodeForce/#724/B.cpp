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
#include<unordered_map>

using namespace std;

int t, n;

int main() {
    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        string s; cin >> s;

        string sol = "";

        bool sol1 = false; int s1Fre = 0;
        unordered_map<char, int> d1;
        for (char ch : s) {
            if (!d1[ch]) s1Fre++;
            d1[ch]++;
        }

        if (s1Fre < 26) {
            for (int i = 0; i < 26; i++) {
                if (!d1['a' + i]) {
                    sol += 'a' + i;
                    cout << sol << endl; sol1 = true; break;
                }
            }
            continue;
        }

        int s2Fre = 0; bool sol2 = false;
        for (int j = 0; j < 26; j++) {
            char c1 = 'a' + j;

            unordered_map<char, int> d2; s2Fre = 0;

            for (int i = 0; i < n - 1; i++) {
                if (s[i] == c1) {
                    if (!d2[s[i + 1]]) s2Fre++;
                    d2[s[i + 1]]++;
                }
            }

            if (s2Fre < 26) {
                for (int i = 0; i < 26; i++) {
                    if (!d2['a' + i]) {
                        sol += c1; sol += 'a' + i;
                        cout <<  sol << endl; sol2 = true; break;
                    }
                }
                break;
            }
        }
        if (sol2) continue;

        int s3Fre = 0; bool sol3 = false;
        for (int i = 0; i < 26; i++) {
            char c1 = 'a' + i;

            for (int j = 0; j < 26; j++) {
                char c2 = 'a' + j;

                unordered_map<char, int> d3; s3Fre = 0;

                for (int i = 0; i < n - 2; i++) {
                    if (s[i] == c1 && s[i + 1] == c2) {
                        if (!d3[s[i + 2]]) s3Fre++;
                        d3[s[i + 2]]++;
                    }
                }

                if (s3Fre < 26) {
                    for (int i = 0; i < 26; i++) {
                        if (!d3['a' + i]) {
                            sol += c1; sol += c2;  sol += 'a' + i;
                            cout << sol << endl; sol3 = true; break;
                        }
                    }

                    break;
                }

                if (sol3) break;
            }

            if (sol3) break;
        }

    }

    return 0;
}