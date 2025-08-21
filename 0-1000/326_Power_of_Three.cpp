// same to 231. Power of Two
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int len = log(n)/log(3);
        if (n != pow(3, len) && n != pow(3, len+1)) return false;
        return true;
    }
};
