// pow(x, n) =  exp(n*log(x))
#include <cmath>
class Solution {
public:
    double myPow(double x, int n) {
        if (x > 0) return exp(n*log(x));
        else if (x == 0) return 0;
        else if ((n % 2) == 0) return exp(n*log(-x));
        else return -exp(n*log(-x));
        return exp(n*log(x));
    }
};
