// https://leetcode.com/problems/add-digits/
// math

class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        
        while (num) {
            res += (num % 10);
            num /= 10;
            
            if (!num && res >= 10) {
                num = res; res = 0;
            }
            
           
        }
        return res;
    }
};
