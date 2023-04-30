// DP
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>

using namespace std;

int t, m;
long long UB = 1e9 + 7;

string nAddOne(string n, int m1) {

	for (int i = 0; i < m1; i++) {
		string nas = "";
		for (char ch : n) {
			if (ch == '9') nas += "01";
			else nas += (ch + 1);
		}
		n = nas;
	}
	return n;
}

int main() {
	cin >> t;
	int caseNum = 1;

	while (t) {
		t--;
		int cost = 0;

		string n; cin >> n;
		cin >> m;
		
		string zero = "0";

		vector<string> o2n(10);
		o2n[0] = nAddOne(zero, m);
		for (int i = 1; i <= 9; i++) o2n[i] = nAddOne(o2n[i - 1], 1);

		vector<int> onL(10);
		for (int i = 0; i <= 9; i++) onL[i] = o2n[i].size();

		long long  res = 0;
		for (char ch : n) {
			res += onL[ch - '0']; res %= UB;
		}
		
		cout << res << endl;
	}
	return 0;
}