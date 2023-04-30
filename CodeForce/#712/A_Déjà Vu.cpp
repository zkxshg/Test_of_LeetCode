// string
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

int t;

bool ifPali(string& s) {
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l] != s[r]) return false;
		l++; r--;
	}
	return true;
}

int main() {
	cin >> t;

	while (t) {
		t--;

		string str = "";
		cin >> str;

		int slen = str.size();

		int mid = slen / 2;

		bool dejavu = false; string res = "";

		string head = 'a' + str;
		if (!ifPali(head)) {
			res = 'a' + str;
			dejavu = true;
		}

		for (int i = 0; i < mid; i++) {
			if (dejavu) break;

			if (str[i] != str[slen - 1 - i] || str[slen - 2 - i] != 'a') {
				dejavu = true;

				res += str.substr(0, i + 1);
				res += 'a';
				res += str.substr(i + 1, slen - i - 1);

				break;
			}
		}

		if (dejavu) {
			cout << "YES" << endl;
			cout << res << endl;
		}
		else cout << "NO" << endl;
	}

	return 0;
}