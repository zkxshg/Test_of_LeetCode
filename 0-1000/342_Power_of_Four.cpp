// log2(num) % 2 == 0 && num = pow(2, log2(num))
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        int l2a = log2(num) + 1;
        if ((l2a % 2) != 1) return false;
        int p4 = pow(2,l2a-1);
        if (p4 != num) return false;
        return true;  
    }
};
