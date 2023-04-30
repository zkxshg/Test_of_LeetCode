// 9  * 10^0 * 1 + 9 * 10^1 * 2 + 9 * 10^2 * 3 + 9 * 10^3 + 4 ...
class Solution {
public:
    int findNthDigit(int n) {
        long long lev = 0, thre = 9;
        while (n > thre) {
            lev++;
            thre += pow(10, lev) * 9 * (lev + 1);
        }  
        long long pre = thre - pow(10, lev) * 9 * (lev + 1);
        long long num = (n - pre - 1) / (lev + 1) + pow(10, lev);
        long long pos = (n - pre - 1) % (lev + 1);   
        long long res = to_string(num)[pos] - '0';      
        return res;
    }   
};
