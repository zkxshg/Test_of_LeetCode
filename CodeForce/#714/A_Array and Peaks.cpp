// Greedy
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int t, n, k;

int main() {
	cin >> t;
	int caseNum = 1;

	while (t) {
		t--;
		int cost = 0;

		cin >> n; cin >> k;

		if (k == 0) {
			for (int i = 0; i < n; i++) cout << i + 1 << " ";
			cout << endl;
			continue;
		}

		if (n < 3 || k > (n - 3) / 2 + 1) {
			cout << -1 << endl;
			continue;
		}

		vector<int> A(n);
		for (int i = 0; i < n; i++) A[i] = i + 1;

		

		vector<int> R(n); vector<int> P;
		for (int i = 1; i < n; i += 2) {
			R[i] = A.back(); A.pop_back();

			P.push_back(i);
			if (P.size() == k) break;
		}

		reverse(P.begin(), P.end());
		for (int i = 0; i < n; i++) {
			if (!P.empty() && i == P.back()) {
				P.pop_back();
				continue;
			}

			R[i] = A.back(); A.pop_back();
		}

		for (int i = 0; i < n; i++) cout << R[i] << " ";
		cout << endl;
	}

	return 0;
}