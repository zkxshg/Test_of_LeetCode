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

int n, m, c;


int main() {
    cin >> n;

    vector<vector<ll> > item;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);

        c = nums[i];
        vector<ll> ci(c);
        for (int j = 0; j < c; j++) scanf("%lld", &ci[j]);
        
        item.emplace_back(ci);
    }

    cin >> m;
    vector<vector<int> > ban;
    unordered_map<string, int> banlist;

    for (int i = 0; i < m; i++) {
        vector<int> B(n); string list = "";

        for (int j = 0; j < n; j++) {
            scanf("%d", &B[j]); list += to_string(B[j]) + 'c';
        }

        ban.emplace_back(B); banlist[list] = 1;
    }

    vector<vector<int> > bfs = {nums};



    sort(heros.begin(), heros.end());

    cin >> m;

    while (m) {
        m--;

        cin >> def; cin >> atk;

        ll res = 0, zero = 0;

        cout << res << endl; continue;
    }


    return 0;
}