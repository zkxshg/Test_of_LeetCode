// https://leetcode.com/problems/three-divisors/

class Solution {
public:
    bool isThree(int n) {
        int sn = sqrt(n);
        
        int num = 2;
        for (int i = 2; i <= sn; i++) {
            if (!(n % i)) {
                if (n / i == i) num++;
                else num += 2;
            }
            if (num > 3) break;
        }
        
        return (num == 3);
   
    }
};
