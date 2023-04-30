// https://leetcode.com/problems/base-7/
// math

class Solution {
public:
    string convertToBase7(int num) {
        bool pos = (num >= 0)? true : false;
        num = abs(num);
        
        string res = "";
        
        if (!num) res = "0";
        while (num) {
            res = to_string(num % 7) + res;
            num /= 7;
        }
        
        if (!pos) res = "-" + res;
        
        return res;
    }
};
