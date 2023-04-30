// Bit manipulation
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define ll long long

ll qmul(ll x, ll y, ll mod)
{
	ll ret = 0;
	while (y) {
		if (y & 1)
			ret = (ret + x) % mod;
		x = x * 2 % mod;
		y >>= 1;
	}
	return ret;
}

int t, n;

int main() {
	cin >> t;
	int caseNum = 1;

	while (t) {
		t--;
		int cost = 0;

		cin >> n; 

		vector<int> A(n);
		for (int i = 0; i < n; i++) cin >> A[i];

		// get max 
		int maxA = *max_element(A.begin(), A.end());
		// get max Level
		int lv = 1;  while (maxA >= pow(2, lv)) lv++;

		// Check common of each level 
		int cand = 0;
		for (int i = 0; i < lv; i++) {
			bool zero = false;
			for (int j : A) {
				if (!(j & (1 << i))) {
					zero = true; break;
				}
			}
			if (!zero) cand += pow(2, i);
		}

		// search the candidates
		int canN = 0;
		for (int a : A)
			if (a == cand) canN++;

		if (canN < 2) {
			cout << 0 << endl; continue;
		}

		int res = 1;
		res = qmul(canN, canN - 1, 1e9+7);

		for (int i = 1; i <= n - 2; i++) res = qmul(res, i, 1e9 + 7);

		cout << res << endl; continue;
	}

	return 0;
}