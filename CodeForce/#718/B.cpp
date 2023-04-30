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

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (pos[i][1] == pos[j][1] && pos[i][2] > pos[j][2]) {
                    int x = pos[i][1];

                    int tem = path[x][pos[i][2]]; 
                    path[x][pos[i][2]] = path[x][pos[j][2]];
                    path[x][pos[j][2]] = tem;

                    tem = pos[j][2];
                    pos[j][2] = pos[i][2];
                    pos[i][2] = tem;
                }
            }
        }



        for (int i = 0; i < m; i++) {
            int x = pos[i][1], y = pos[i][2];
            int temp = path[x][y];
            path[x][y] = path[x][i];
            path[x][i] = temp;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << path[i][j] << " ";
            cout << endl;
        }
                    
    }

    return 0;
}