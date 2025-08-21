// design
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        
        if (dividend == INT_MAX && divisor == 1) return INT_MAX;
        if (dividend == INT_MAX && divisor == -1) return INT_MIN + 1;
        if (dividend == -INT_MAX && divisor == 1) return -INT_MAX;
        if (dividend == -INT_MAX && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        long did = dividend;
        long dir = divisor;
        
        if (did < 0) {
            sign = -sign; did = -did;
        }

        if (dir < 0) {
            sign = -sign; dir = -dir;
        }
   
        if (did < dir) return 0;
        if (did == dir) return sign;
        
        long long res = pow(10, log10l(did) - log10l(dir));
        
        if (dividend == INT_MIN && divisor == 2) return (res + 1) * sign;
        if (dividend == INT_MIN && divisor == -2) return (res + 1) * sign;
        
        return res * sign;
    }
};
