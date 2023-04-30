// https://leetcode.com/problems/simplified-fractions/
// math

class Solution {
public:
    int gcd(int m, int n) {
        int t = 1;
        while (t != 0) {
            t = m % n;
            m = n;
            n = t;
        }
        return m;
    }
    
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        if (n < 2) return res;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                string dec = ""; dec += to_string(j); dec += "/"; dec += to_string(i);
                if (gcd(i, j) == 1) res.push_back(dec);
            }
        }
        
        return res;
    }
};
