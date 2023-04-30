// https://leetcode.com/problems/bulb-switcher/description/
// math

class Solution {
public:
    int bulbSwitch(int n) {
        if (n < 2) return n;

        int res = 1;
        for (int i = 2; i <= n; i++) {
            long long i2 = i * i;
            
            if (i2 <= n) res++;
            else break;
        }
        
        return res;
    }
};
