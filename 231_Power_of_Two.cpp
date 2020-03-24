// n == pow(2, int(log2(n)))
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n != pow(2, int(log2(n)))) return false;
        return true;
    }
};
