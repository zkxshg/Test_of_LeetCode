// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/
// Greedy

class Solution {
public:
    int convertTime(string current, string correct) {
        int h1 = 0, h2 = 0, m1 = 0, m2 = 0;
        
        h1 = current[0] - '0'; h1 = h1 * 10 + current[1] - '0';
        m1 = current[3] - '0'; m1 = m1 * 10 + current[4] - '0';
        
        h2 = correct[0] - '0'; h2 = h2 * 10 + correct[1] - '0';
        m2 = correct[3] - '0'; m2 = m2 * 10 + correct[4] - '0';
        
        int t1 = h1 * 60 + m1, t2 = h2 * 60 + m2;
        
        int res = 0, div = t2 - t1;
        
        while (div) { 
            if (div >= 60) {
                res += div / 60; div %= 60;
            }
            else if (div >= 15) {
                res += div / 15; div %= 15;
            }
            else if (div >= 5) {
                res += div / 5; div %= 5;
            }
            else {
                res += div; break;
            }
        }
        
        return res;
    }
};
