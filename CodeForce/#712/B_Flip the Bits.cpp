// Greedy
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

#define MaxValue 9999999

using namespace std;

int t, slen;

int main() {
	cin >> t;

	while (t) {
		t--;

		cin >> slen;

		string s1, s2;
		cin >> s1;
		cin >> s2;

		vector<int> a1(slen); vector<int> a1_0(slen); vector<int> a1_1(slen); 

		for (int i = 0; i < slen; i++) {
			a1[i] = s1[i] - '0';

			if (i > 0) {
				if (a1[i]) {
					a1_1[i] = a1_1[i - 1] + 1; a1_0[i] = a1_0[i - 1];
				}
				else {
					a1_1[i] = a1_1[i - 1]; a1_0[i] = a1_0[i - 1] + 1;
				}	
			}
			else {
				if (a1[0]) a1_1[0] = 1;
				else a1_0[0] = 1;
			}
		}

		vector<int> a2(slen); 
		for (int i = 0; i < slen; i++) a2[i] = s2[i] - '0';

		int flip = 0;

		bool yes = true;

		for (int i = slen - 1; i >= 0; i--) {
			if (a1[i] != abs(a2[i] - flip)) {
				if (a1_0[i] != a1_1[i]) {
					yes = false; break;
				}
				else flip = 1 - flip;
			}
		}
		

		if (yes) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}