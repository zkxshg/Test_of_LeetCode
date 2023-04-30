// greedy + stack
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        s += 's';
        int res = 0;
        int a = 0, b = 0, ab = 0, ba = 0;
        for (char ch : s) {
            if (ch != 'a' && ch != 'b') {
                if (a || b) {
                    if (a && b) {
                        if (x > y) res += ab * x + (min(a, b) - ab) * y;
                        else res += ba * y + (min(a, b) - ba) * x;
                    } 
                    a = 0; b = 0; ab = 0; ba = 0;
                } 
            }
            else {
                if (ch == 'a') {
                    a++;
                    if (ba < b) ba++;
                }
                else {
                    b++;
                    if (ab < a) ab++;
                }
            }
        }
        return res;
    }
};
