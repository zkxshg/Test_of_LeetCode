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
#include <unordered_map>

using namespace std;


int n, q;

int main() {
    cin >> n; cin >> q;

    vector<int> card(n);
    for (int i = 0; i < n; i++) cin >> card[i];

    vector<int> Q(q);
    for (int i = 0; i < q; i++) cin >> Q[i];

    unordered_map<int, int> color2pos;

    // Rec highest of each color
    int qc = 0, pos = 0;
    while (qc < 50 && pos < n) {
        if (!color2pos[card[pos]]) {
            color2pos[card[pos]] = pos + 1; qc++;
        }
        pos++;
    }

    for (int i = 0; i < q; i++) {
        int qu = Q[i];

        int op = color2pos[qu];
        cout << op << " ";

        for (int c = 1; c < qu; c++)
            if (color2pos[c] < op) color2pos[c]++;

        for (int c = qu + 1; c <= 50; c++)
            if (color2pos[c] < op) color2pos[c]++;

        color2pos[qu] = 1;
    }

    // cout << endl;

    return 0;
}