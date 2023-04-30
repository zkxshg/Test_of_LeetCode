// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// design
class Solution {
public:
    int numberOfSteps (int num) {
        int couter = 0;
        while(num != 0){
            if (num % 2 == 1) num -= 1;
            else num /= 2;
            couter++;
        }
        return couter;
    }
};
