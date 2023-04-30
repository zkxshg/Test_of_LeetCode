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
    int caseNum = 1;

    while (t) {
        t--;
        int cost = 0;

        cin >> n; 

        if (n <= 3) {
            cout << "Bob" << endl; continue;
        }

        vector<int> dp(n + 1);

        dp[1] = -1; dp[2] = -1; dp[3] = -1;

        for (int i = 2; i < n; i++) {
            vector<pair<int, int> > div;
            int ub = sqrt(i);
            for (int j = 2; j <= ub; j++) 
                if (i % j == 0) 
                    div.push_back(make_pair(j, i / j));

            if (div.empty()) {
                dp[i] = -1;
                if (2 * i <= n) dp[2 * i] = 1;
            }
            else {
                if (2 * i <= n) {
                    if (dp[i] < 0) dp[2 * i] = 1;
                    else if (!dp[2 * i]) dp[2 * i] = -1;
                }

                for (auto& p : div) {
                    int aim = p.first * (p.second + 1); if (aim > n) continue;
                    if (dp[i] < 0) dp[aim] = 1;
                    else if (!dp[aim]) dp[aim] = -1;

                    int aim2 = p.second * (p.first + 1); if (aim2 > n) continue;
                    if (dp[i] < 0) dp[aim2] = 1;
                    else if (!dp[aim2]) dp[aim2] = -1;
                }
            }
        }

        if (dp[n] > 0) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }

    return 0;
}