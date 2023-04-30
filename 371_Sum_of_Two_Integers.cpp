// https://leetcode.com/problems/sum-of-two-integers/
// bit calculation:
// a + b = while(b){ tem = (a ^ b); b = (a & b) << 1; a = tem; }
class Solution {
public:
    int getSum(int a, int b) {
        int tem = 0;
        bool nega = false; 
        if (a < 0 && b < 0){
            a = -a;
            b = -b;
            nega = true;
        }
        while(b){
            tem = (a ^ b);
            if (b == -2147483648) b = 0;
            else b = (a & b) << 1;
            a = tem;
        }
        if (nega) return -a;
        return a;
    }
};
