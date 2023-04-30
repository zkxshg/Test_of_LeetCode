// greedy - A*: O(nlogn)
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        long long x = X;
        long long y = Y;
        
        while (x != y) {
            if (x >= y) {
                res += (x - y);
                break;
            }
            
            int Do = dist(2 * x, y);
            int De = dist(x - 1, y);
            
            if (De < Do) x -= 1;
            else x *= 2;
            //cout << "x = " << x << endl;
            res++;
        }
        
        return res;
    }
    
    long long dist(long long a, long long b) {
        if (a == 0) return INT_MAX;
        
        long long cou = 0;
        while (a < b) {
            a *= 2;
            cou++;
        }
        cou += (a - b);
        return cou;
    }
};
