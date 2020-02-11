//  Palindrome_Number : (x / int(pow(10, n)) % 10) == (x / int(pow(10, len - n)) % 10)
#include<cmath>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int len = int(log10(x));
        bool pali = true;
        int n = 0;
        int m;
        while (n < len / 2 + 1)
        {
            m = len - n;
            if ((x / int(pow(10, n)) % 10) != (x / int(pow(10, m)) % 10))
            {
                pali = false;
                break;
            }
            n++;
        }
        return pali;
    }
};
