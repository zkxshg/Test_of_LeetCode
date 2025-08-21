class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 4) return 0;
        long long e5 = 5;
        int cou = 0;
        while(e5 <= n){
            cou += n / e5;
            e5 *= 5;
        }
        return cou;
    }
};
