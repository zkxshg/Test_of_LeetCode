// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
// bit maniputation

class Solution {
public:
    bool get_bit(int x, int n){ 
        return x & (1 << n); 
    }

    int minFlips(int a, int b, int c) {
        int oper = 0;
        for (int i = 0; i <= 30; i++) {
            bool ai = get_bit(a, i), bi = get_bit(b, i), ci = get_bit(c, i);

            if ((ai | bi) == ci) continue;

            if (ci) {
                if (!(ai | bi)) oper++;
            }
            else {
                if (ai & bi) oper += 2;
                else oper++;
            }
        }

        return oper;
    }
};
