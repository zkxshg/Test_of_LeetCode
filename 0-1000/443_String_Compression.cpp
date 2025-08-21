// https://leetcode.com/problems/string-compression/
// two pointers + RLE
class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size(); if (len < 2) return len;
        
        int cou = 1, step = 0, p = 0;
        while (p < len) {
            if (p == len - 1 || chars[p] != chars[p + 1]) {
                if (cou == 1) {
                    chars[step] = chars[p];
                    step++; p++;
                }
                else {
                    chars[step] = chars[p]; step++;
                    vector<int> nums;
                    while (cou > 0) {
                        nums.push_back(cou % 10);
                        cou /= 10;
                    }
                    while (!nums.empty()) {
                        chars[step] = '0' + nums.back(); step++;
                        nums.pop_back();
                    }
                    p++;
                    cou = 1;
                }
            }
            else {
                cou++; p++;
            }
        }
        
        return step;
    }
};
