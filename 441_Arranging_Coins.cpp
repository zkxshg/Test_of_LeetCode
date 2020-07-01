// brute-force or binary search
class Solution {
public:
    int arrangeCoins(int n) {
        if (n < 2) return n;
        int result = 1;
        while (n >= result) {
            n -= result;
            result++;
        }
        return result - 1;
    }
};
