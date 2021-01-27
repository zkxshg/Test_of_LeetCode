// math
class Solution {
public:
    int concatenatedBinary(int n) {
        if (n == 1) return 1;
        if (n == 2) return 6;
        
        long long res = 6, ub = 1e9 + 7;
        
        int bi = 4;
        for (int i = 3; i <= n; i++) {
            if (bi <= i) bi *= 2;
            res = res * bi + i;
            res %= ub;
        }
        
        return res;
    }
};
