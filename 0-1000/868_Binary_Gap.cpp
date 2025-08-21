// https://leetcode.com/problems/binary-gap/
// Bit Maniputation

class Solution {
public:
    int binaryGap(int n) {
        int pre = -1, lv = 0, res = 0;
        
        while (n >= (1 << lv)) {
            if ((n >> lv) & 1) {
                if (pre < 0) pre = lv;
                else {
                    res = max(res, lv - pre); pre = lv;
                }
            }
            
            lv++;
        }
        
        return res;
    }
};
