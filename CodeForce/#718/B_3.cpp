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

static bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

int t, n, m;

int main() {
    cin >> t;

    while (t) {
        t--;

        cin >> n; cin >> m;

        vector<vector<int> > path(n, vector<int>(m));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) cin >> path[i][j];

        vector<vector<int> > pos;
        make_heap(pos.begin(), pos.end(), cmp);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pos.empty()) {
                    pos.push_back({path[i][j], i, j});
                    push_heap(pos.begin(), pos.end(), cmp);
                }
                else {
                    pos.push_back({ path[i][j], i, j });
                    push_heap(pos.begin(), pos.end(), cmp);

                    if (pos.size() > m) {
                        pop_heap(pos.begin(), pos.end(), cmp); pos.pop_back();
                    }
                }
            }
        
        }
        sort_heap(pos.begin(), pos.end(), cmp);

        vector<vector<int> > res(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            vector<int> v = pos[i];

            res[v[1]][i] = v[0];
            path[v[1]][v[2]] = -1;
        }

        for (int i = 0; i < n; i++) {
            int tp = 0;
            for (int j = 0; j < m; j++) {
                if (res[i][j] > 0) continue;
                else {
                    while (path[i][tp] <= 0) tp++;
                    res[i][j] = path[i][tp]; tp++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << res[i][j] << " ";
            cout << endl;
        }
                    
    }

    return 0;
}