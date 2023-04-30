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

int t;
string s;

int titleToNumber(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) sum += (s[s.size() - 1 - i] - 'A' + 1) * pow(26, i);
    return sum;
}

string convertToTitle(int n) {
    string result;

    while (n > 0) {
        int temp = n % 26;
        if (temp == 0) temp = 26;
        char temc = 'A' + temp - 1;
        result.push_back(temc);
        if (temp == 26) n = (n / 26) - 1;
        else n = n / 26;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> s;

        int n = s.size(), pos = 0;

        string s1 = ""; while (pos < n && s[pos] >= 'A' && s[pos] <= 'Z') { s1 += s[pos]; pos++; }
        int s2 = 0;     while (pos < n && s[pos] >= '0' && s[pos] <= '9') { s2 = s2 * 10 + (s[pos] - '0'); pos++; }

        if (pos >= n) {
            int si1 = titleToNumber(s1);
            cout << 'R' << s2 << 'C' << si1 << endl;
        }
        else {
            string s3 = ""; while (pos < n && s[pos] >= 'A' && s[pos] <= 'Z') { s3 += s[pos]; pos++; }
            int s4 = 0;     while (pos < n && s[pos] >= '0' && s[pos] <= '9') { s4 = s4 * 10 + (s[pos] - '0'); pos++; }

            string si4 = convertToTitle(s4);
            cout << si4 << s2 << endl;

        }
    }

    return 0;
}