// Binary search
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if (guess(1) == 0) return 1;
        if (guess(n) == 0) return n;
        unsigned int start = 1;
        unsigned int least = n;
        while (least - start >= 0){
            if (least - start <= 1) return least;
            unsigned int k = (least + start) / 2;
            if (guess(k) == 0) return k;
            else if (guess(k) == -1) least = k;
            else start = k;
        }
        return 0; 
    }
};
