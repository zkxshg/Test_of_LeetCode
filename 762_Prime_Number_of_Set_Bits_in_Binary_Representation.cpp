// brute-force as num1 <= 32
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int counter = 0;
        int num1 = 0;
        for(int i = L; i < R + 1; i++){
            num1 = __builtin_popcount(i);
            if(num1==2||num1==3||num1==5||num1==7||num1==11||num1==13||num1==17||num1==19||num1==23||num1==29||num1==31) counter++;
        }
        return counter;
    }
};
