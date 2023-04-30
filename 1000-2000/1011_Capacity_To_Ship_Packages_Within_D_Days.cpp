// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
// Binary search

class Solution {
public:
    #define ll long long 

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        vector<ll> sumW(n); sumW[0] = weights[0];
        ll maxW = weights[0];
        for (int i = 1; i < n; i++) {
            if (maxW < weights[i]) maxW = weights[i];
            sumW[i] = sumW[i - 1] + weights[i];
        }

        ll temW = max(maxW, sumW[n - 1] / days);

        bool ship = false;
        while (!ship) {
            int st = 0, d = days; 
            ll aim = temW;

            while (d > 0 && st < n) {
                int nex = upper_bound(sumW.begin() + st, sumW.end(), aim) - sumW.begin();
  
                st = nex; 

                aim = sumW[st - 1] + temW;
                d--;
            }

            if (st >= n) {
                ship = true; break;
            }

            temW++;
        }

        return temW;
    }
};
