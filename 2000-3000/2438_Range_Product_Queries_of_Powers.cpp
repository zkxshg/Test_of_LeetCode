// 2438. Range Product Queries of Powers
// Link: https://leetcode.com/problems/range-product-queries-of-powers/
// Lang: C++
// Date: 2025-08-21 20:50:25.490 UTC

class Solution {
public:
    #define ll long long
    ll ub = 1e9 + 7;

    ll qpow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % ub;
            a = a * a % ub;
            b >>= 1;
        }
        return res; // a^b
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> inds;
        int pos = 0;
        while (n) {
            if (n & 1) inds.push_back(pos);
            pos++;
            n = (n >> 1);
            // cout << n << endl;
        }

        int m = inds.size();
        vector<int> preSum(m); preSum[0] = inds[0];
        for (int i = 1; i < m; i++) {
            preSum[i] = preSum[i - 1] + inds[i];
        }

        vector<int> res;
        for (auto& q : queries) {
            int pow = 0, st = q[0], en = q[1];
            
            if (st == 0) pow = preSum[en];
            else pow = preSum[en] - preSum[st - 1];
            // cout << pow << endl;
            res.push_back(qpow(2, pow));
        }

        return res;       
    }
};
