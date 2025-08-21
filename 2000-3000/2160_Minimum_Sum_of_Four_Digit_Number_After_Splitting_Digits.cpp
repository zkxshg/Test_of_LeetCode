// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
// combination

class Solution {
public:
    int minimumSum(int num) {
        int a, b, c, d;
        a = num % 10; num /= 10;
        b = num % 10; num /= 10;
        c = num % 10; num /= 10;
        d = num % 10; num /= 10;
        
        int res = 20000;
        res = min(res, (a * 10 + c) + (b * 10 + d));
        res = min(res, (a * 10 + b) + (c * 10 + d));
        res = min(res, (a * 10 + b) + (d * 10 + c));
        res = min(res, (b * 10 + a) + (c * 10 + d));
        res = min(res, (b * 10 + a) + (d * 10 + c));
        res = min(res, (c * 10 + a) + (d * 10 + b));
        
        return res;  
    }
};
