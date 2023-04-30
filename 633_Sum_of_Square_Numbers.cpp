// exausted search
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 2) return true;
        int en = sqrt(c); 
        for (int i = 1; i <= en; i++) {
            int b = c - i * i;
            int sqb = sqrt(b);
            if (sqb * sqb == b) return true;
        }
        return false;
    }
};
