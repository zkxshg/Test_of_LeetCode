// https://leetcode.com/problems/count-vowels-permutation/
// DP

class Solution {
public:

    #define ll long long
    
    int countVowelPermutation(int n) {
        if (n == 1) return 5;
        
        vector<vector<ll> > C(5, vector<ll>(n + 1));
        for (int i = 0; i < 5; i++) C[i][1] = 1;
        
        ll ub = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            C[0][i] = (C[1][i - 1] + C[2][i - 1] + C[4][i - 1]) % ub; // a
            C[1][i] = (C[0][i - 1] + C[2][i - 1]) % ub; // e
            C[2][i] = (C[1][i - 1] + C[3][i - 1]) % ub; // i
            C[3][i] =  C[2][i - 1] % ub; // o
            C[4][i] = (C[2][i - 1] + C[3][i - 1]) % ub; // u
        }
        
        ll res = 0;
        for (int i = 0; i < 5; i++) res = (res + C[i][n]) % ub;
        
        return res;
    }
};
