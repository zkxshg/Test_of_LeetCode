// math
class Solution {
public:
    int totalMoney(int n) {
        int st = 1, res = 0, cou = 0;
        while (n > 0) {
            res += st + cou; cou++; n--;
            if (cou == 7) {
                st++; cou = 0;
            }
        }
        return res;
    }
};
